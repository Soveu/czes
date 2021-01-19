#include "NetSock/NetSock.cpp"
#include <memory>

const char MAGIC[4] = "czes";
const char PROTOCOL_VERSION = 2;

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
  char move[4];
};

class ClientSocket {
  NetSock sock;
  std::vector<char> buffer;

  ClientSocket() : buffer(0, 65600) {}
  ~ClientSocket() = default;
  ClientSocket(const ClientSocket&) = delete;
  ClientSocket(ClientSocket&&) = default;

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
  bool connect(const char* host, const char* nickname) {
    if(this->sock.Connect(host, 9998) == false) {
      return false;
    }

    size_t len = 0;
    while(nickname[len] != '\0') {
      len += 1;
    }

    if(len > 65530) {
      return false;
    }

    this->buffer.push_back(static_cast<uint8_t>(len));
    this->buffer.push_back(static_cast<uint8_t>(len >> 8));

    this->prepare_message(2);
    this->buffer_append(nickname, len);

    return this->send_bufer();
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

  bool pause_game() {
    this->prepare_message(5);
    return this->send_buffer();
  }

  bool move_piece(const char* move) {
    this->prepare_message(6);
    this->append_buffer(move, 4);
    return this->send_buffer();
  }

  bool move_piece(const char* move) {
    this->prepare_message(7);
    return this->send_buffer();
  }

  bool ask_for_draw() {
    this->prepare_message(8);
    return this->send_buffer();
  }

  /* TODO: send_board */

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

    switch(this->buffer[5]) {
      case PacketType::Connect:
        p.error = PacketError::Shrug;
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
        p.type = this->buffer[5];
        return p;

      case PacketType::MovePiece:
        p.error = PacketError::None;
        p.type = PacketType::MovePiece;
        if(this->sock.ReadAll(&p.move, sizeof(p.move)) == 0) {
          p.error = PacketError::Socket;
        }
        return p;
    }

    assert(false);
    return p;
  }
};
