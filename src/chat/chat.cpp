#include "chat.hpp"
void Chat::AddUser(const std::string& user) {
  users_.push_back(user);
}
const std::vector<std::string>& Chat::GetUsers() const {
  return users_;
}
