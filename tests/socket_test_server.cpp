#include "socket.cpp"

#include <unistd.h>
#include <iostream>

int main() {
  auto sock = new_ipv4_tcp_socket();
  sock = bind_tcp_socket(sock, 49714);
  sock = listening_socket(sock);

  std::cout << "Waiting for connection" << std::endl;

  auto new_handle = accept_connection(sock);

  char buf[4096];
  for(;;) {
    size_t bytes_read = read(new_handle, buf, sizeof(buf));

    if(bytes_read <= 0) {
      perror("server");
      break;
    }

    buf[bytes_read] = 0;
    std::cout << buf;
  }
}
