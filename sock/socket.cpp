#include "NetSock/NetSock.cpp"
#include <vector>
#include <string>
#include <assert.h>

/*
 * class Socket
 * Ta klasa służy jako interfejs do wysyłania wiadomości.
 * Zamiast ręcznie przygotowywać pakiet, po prostu używasz dostępnych funkcji.
 * Każda (z wyjątkiem `recieve_message`) zwraca boola oznaczającego czy wiadomość udało się wysłać.
 *
 * `recieve_message` zwraca całego structa `Packet`
 * Najpierw należy sprawdzić, czy error == PacketError::None, następnie typ pakietu.
 * - PacketType::Connect == `nickname` będzie zawierał nazwe użytkownika
 * - PacketType::MovePiece == `move` będzie zawierał opis ruchu taki sam jak użytkowik ma wpisać
 * - PacketType::Board == `board` będzie zawierał opis planszy
 */

/*
 * class ServerSocket
 * Ta klasa zawiera 2 pola:
 * - `player_sock` == tablica 2 `class Socket`, każda na gracza
 * - `nickname` == tablica 2 `std::string`, każda na gracza
 *
 * oraz 1 metode `wait_for_player`, która czeka na połączenie od gracza, gdy jeszcze nie ma ich dwóch
 *
 * Żeby odebrać wiadomość od gracza, po prostu użyj `player_sock[i].recieve_message()`
 */

const char MAGIC[4] = {'c', 'z', 'e', 's'};
const char PROTOCOL_VERSION = 2;

using BoardType = short[8][8];

enum PacketType : uint8_t {
  Ping = 0,
  Pong,
  Connect,
  Disconnect,
  PauseGame,
  ResumeGame,
  MovePiece,
  Surrender,
  AskForDraw,
  Board,
  SomethingWentWrong,
};

enum PacketError : uint8_t {
  None = 0,
  Socket,
  Magic,
  ProtocolVersion,
  Type,
  Disconnected,
  Shrug = 255
};

struct Packet {
  PacketError error;

  // Only contains data if error == None
  PacketType type;

  // Only contains data if type == Connect
  std::string nickname;

  // Only contains data if type == MovePiece
  char move[8];

  // Only contains data if type == Board 
  BoardType board;
};

class Socket {
public:
  NetSock sock;
  std::vector<char> buffer;

private:
  void buffer_append(const char* ptr, size_t len) {
    for(size_t i=0; i<len; i+=1) {
      this->buffer.push_back(ptr[i]);
    }
  }
  void prepare_message(char message_type) {
    buffer.clear();
    this->buffer_append(MAGIC, 4);
    buffer.push_back(PROTOCOL_VERSION);
    buffer.push_back(message_type);
  }
  bool send_buffer() {
    return this->sock.WriteAll(this->buffer.data(), this->buffer.size()) != 0;
  }

public:
  Socket() : buffer(65600, 0) {}
  ~Socket() = default;
  Socket(const Socket&) = delete;
  Socket(Socket&&) = default;

  bool connect(const char* host, const char* nickname) {
    if(this->sock.Connect(host, 9998) == false) {
      return false;
    }

    size_t len = 0;
    len = strlen(nickname);
    assert(len > 1 && len < 65530);

    this->buffer.push_back(static_cast<uint8_t>(len));
    this->buffer.push_back(static_cast<uint8_t>(len >> 8));

    this->prepare_message(2);
    this->buffer_append(nickname, len);

    return this->send_buffer();
  }

  bool ping() {
    this->prepare_message(0);
    return this->send_buffer();
  }

  bool pong() {
    this->prepare_message(1);
    return this->send_buffer();
  }

  bool disconnect() {
    this->prepare_message(3);
    if(this->send_buffer() == false) {
      return false;
    }
    return this->sock.Disconnect();
  }

  bool pause_game() {
    this->prepare_message(4);
    return this->send_buffer();
  }

  bool resume_game() {
    this->prepare_message(5);
    return this->send_buffer();
  }

  bool move_piece(const char* move, size_t len) {
    assert(len <= 7 && len >= 4);
    char buf[8];
    memset(buf, 0, sizeof(buf));
    memcpy(buf, move, len);

    this->prepare_message(6);
    this->buffer_append(buf, sizeof(buf));
    return this->send_buffer();
  }

  bool surrender() {
    this->prepare_message(7);
    return this->send_buffer();
  }

  bool ask_for_draw() {
    this->prepare_message(8);
    return this->send_buffer();
  }

  bool send_board(const BoardType& board) {
    this->prepare_message(9);
    this->buffer_append((char*)board, sizeof(BoardType));
    return this->send_buffer();
  }

  bool something_went_wrong() {
    this->prepare_message(10);
    return this->send_buffer();
  }

  Packet recieve_message() {
    this->buffer.resize(65600);
    Packet p = Packet();

    if(this->sock.ReadAll(this->buffer.data(), 6) == 0) {
      p.error = PacketError::Socket;
      return p;
    }

    if(memcmp(this->buffer.data(), MAGIC, 4) != 0) {
      p.error = PacketError::Magic;
      return p;
    }

    if(this->buffer[4] != PROTOCOL_VERSION) {
      p.error = PacketError::ProtocolVersion;
      return p;
    }

    uint16_t len = 0;
    std::string nickname;
    switch(this->buffer[5]) {
      case PacketType::Connect:

        if(this->sock.ReadAll(&len, 2) == 0) {
          p.error = PacketError::Socket;
          return p;
        }

        assert(len > 0);
        nickname.resize(len+1);

        if(this->sock.ReadAll(&nickname[0], len) == 0) {
          p.error = PacketError::Socket;
          return p;
        }
        nickname[len] = '\0';

        p.error = PacketError::None;
        p.type = PacketType::Connect;
        p.nickname = nickname;
        return p;

      case PacketType::Disconnect:
        p.error = PacketError::Disconnected;
        return p;

      case PacketType::Ping:
      case PacketType::Pong:
      case PacketType::PauseGame:
      case PacketType::ResumeGame:
      case PacketType::Surrender:
      case PacketType::AskForDraw:
        p.error = PacketError::None;
        p.type = static_cast<PacketType>(this->buffer[5]);
        return p;

      case PacketType::MovePiece:
        p.error = PacketError::None;
        p.type = PacketType::MovePiece;
        if(this->sock.ReadAll(&p.move, sizeof(p.move)) == 0) {
          p.error = PacketError::Socket;
        }
        return p;

      case PacketType::SomethingWentWrong:
        p.error = PacketError::Shrug;
        return p;
    }

    assert(false);
    return p;
  }
};

class ServerSocket {
  NetSock listen_sock;
public:
  class Socket player_sock[2];
  std::string nickname[2];

  ServerSocket() {
    NetSock sock = NetSock();
    sock.ListenAll(9998);
    std::swap(this->listen_sock, sock);
  }
  ~ServerSocket() = default;
  ServerSocket(const ServerSocket&) = delete;
  ServerSocket(ServerSocket&&) = default;

  int wait_for_player() {
    int i=0;
    while(this->player_sock[i].sock.socket == -1) {
      i += 1;
      if(i == 2) return 2;
    }

    NetSock* ptr = this->listen_sock.Accept();
    assert(ptr != NULL);
    // TODO: maybe handle it somehow gracefully

    std::swap(*ptr, this->player_sock[i].sock);
    delete ptr;

    Packet msg = this->player_sock[i].recieve_message();
    assert(msg.error == PacketError::None);
    assert(msg.type == PacketType::Connect);
    std::swap(this->nickname[i], msg.nickname);

    return i;
  }
};

