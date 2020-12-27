#pragma once

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>

#include <stdio.h>
#include <assert.h>

uint32_t string_to_addr(const char* p) {
  return 0;
}

int new_ipv4_tcp_socket() {
  int handle = socket(AF_INET, SOCK_STREAM, 0);
  assert(handle != -1);
  return handle;
}

int bind_tcp_socket(int handle, uint16_t port) {
  in_addr addr;
  addr.s_addr = INADDR_ANY;

  sockaddr_in sa;
  sa.sin_family = AF_INET;
  sa.sin_port = port;
  sa.sin_addr = addr;

  int result = bind(handle, (sockaddr*)&sa, sizeof(sa));
  if(handle == -1) {
    perror("bind");
    assert(false);
  }

  return handle;
}

int listening_socket(int handle) {
  int result = listen(handle, 1);
  assert(result == 0);
  return handle;
}

int accept_connection(int handle) {
  sockaddr_in connection;
  socklen_t len_of_addr = sizeof(connection);

  int new_handle = accept(handle, (sockaddr*)&connection, &len_of_addr);
  assert(new_handle != -1);
  assert(len_of_addr == sizeof(connection));

  return new_handle;
}

void make_connection(int socket, uint32_t address, uint16_t port) {
  in_addr addr;
  addr.s_addr = address;

  sockaddr_in sa;
  sa.sin_family = AF_INET;
  sa.sin_port = port;
  sa.sin_addr = addr;

  int result = connect(socket, (sockaddr*)&sa, sizeof(sa));
  assert(result == 0);
}

