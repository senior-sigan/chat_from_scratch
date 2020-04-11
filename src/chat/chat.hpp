#pragma once

#include <vector>
#include <string>
#include <sstream>

class Chat {
  std::vector<std::string> users_;
 public:
  std::string selectedUser = "";
  std::stringstream textInput;

  void AddUser(const std::string& user);
  const std::vector<std::string>& GetUsers() const;
};
