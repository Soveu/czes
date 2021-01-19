#pragma once

#include <optional>

template <typename T, typename E>
class Result {
  bool iserr;
  union {
    T data;
    E error;
  };

 public:
  bool is_err() const {
    return this->iserr;
  }

  std::optional<const T&> get_data() const {
    if(this->iserr) {
      return {};
    }
    return this->data;
  }
  std::optional<T&> get_data() {
    if(this->iserr) {
      return {};
    }
    return this->data;
  }

  std::optional<const E&> get_error() const {
    if(this->iserr) {
      return this->error;
    }
    return {};
  }
  std::optional<E&> get_error() {
    if(this->iserr) {
      return this->error;
    }
    return {};
  }
};

