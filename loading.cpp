#pragma once

#include <iostream>
#include <filesystem>
#include <array>

#include <assert.h>

#include "definitions.cpp"

/* Parse coord with format "[a-z]+[0-9]+[a-z]+[0-9]+" */
std::array<Coord, 2> parse_coord_classic(const char* str, size_t len) {
  std::array<Coord, 2> result{Coord{0, 0}, Coord{0, 0}};
  size_t i=0;

  for(auto& coord : result) {
    /* "a" is 0, but "aa" is 26 */
    coord.x += (str[i] - 'a');
    i += 1;

    for(; i < len; i += 1) {
      if(str[i] < 'a' || str[i] > 'z') break;
      coord.x += 1;
      coord.x *= ('z' - 'a' + 1);
      coord.x += (str[i] - 'a');
    }

    for(; i < len; i += 1) {
      if(str[i] < '0' || str[i] > '9') break;
      coord.y *= 10;
      coord.y += (str[i] - '0');
    }
  }

  return result;
}

/* Parse coord with format "[0-9]+x[0-9]+_[0-9]+x[0-9]" */
std::array<Coord, 2> parse_coord_num(const char* str, size_t len) {
  std::array<Coord, 2> result{Coord{0, 0}, Coord{0, 0}};

  size_t i=0;
  for(auto& coord : result) {
    for(; i < len; i += 1) {
      if(str[i] == 'x') break;
      assert(str[i] >= '0' && str[i] <= '9');

      coord.x *= 10;
      coord.x += (str[i] - '0');
    }

    i += 1;

    for(; i < len; i += 1) {
      if(str[i] == '-') break;
      assert(str[i] >= '0' && str[i] <= '9');

      coord.y *= 10;
      coord.y += (str[i] - '0');
    }

    i += 1;
  }

  return result;
}

std::array<Coord, 2> parse_coord(const char* str, size_t len) {
  assert(len >= 4);
  if('\0' == str[len-1]) {
    return parse_coord(str, len-1);
  }

  if(str[0] >= '0' && str[0] <= '9') {
    return parse_coord_num(str, len);
  }

  return parse_coord_classic(str, len);
}

//namespace fs = std::filesystem;

int main() {
  {
    char msg[] = "7x8-9x10";
    auto coord_array = parse_coord(msg, sizeof(msg));
    for(const auto& coord : coord_array) {
      std::cout << coord.x << ' ' << coord.y << '\n';
    }
  }

  std::cout << '\n';

  {
    char msg[] = "c2d4";
    auto coord_array = parse_coord(msg, sizeof(msg));
    for(const auto& coord : coord_array) {
      std::cout << coord.x << ' ' << coord.y << '\n';
    }
  }

  std::cout << '\n';

  {
    char msg[] = "zz10aaa44";
    auto coord_array = parse_coord(msg, sizeof(msg));
    for(const auto& coord : coord_array) {
      std::cout << coord.x << ' ' << coord.y << '\n';
    }
  }

  std::cout << '\n';

  {
    for(char a='a'; a<='z'; a += 1) {
      for(char b='a'; b<='z'; b += 1) {
        for(char c='a'; c<='z'; c += 1) {
          char msg[] = {a, b, c, '0', 'z', '1', '\0'};
          auto coord = parse_coord(msg, sizeof(msg)-1);

          std::cout << "'" << msg << "' ";
          std::cout << coord[0].x << ' ' << coord[0].y << "\n";
        }
      }
    }
  }

  /*
  for(const auto& p : fs::directory_iterator("/")) {
    std::cout << p.path() << '\n';
  }
  */
}

