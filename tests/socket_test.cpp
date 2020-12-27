#include "socket.cpp"

#include <iostream>
#include <unistd.h>

int main() {
  auto sock = new_ipv4_tcp_socket();
  sock = bind_tcp_socket(sock, 49714);

  std::cout << "Establishing connection" << std::endl;

  union {
    char bytes[4] = {127, 0, 0, 1};
    uint32_t localaddr;
  };

  make_connection(sock, localaddr, 49714);
  const char msg[] = "Hello World!\n";
  write(sock, msg, sizeof(msg));

  std::cout << "Done\n";
}
