#pragma once

#include <vector>
#include <string>

class Chat {
  std::vector<std::string> users_;
 public:
  std::string selectedUser = "";

  void AddUser(const std::string& user);
  const std::vector<std::string>& GetUsers() const;
};
