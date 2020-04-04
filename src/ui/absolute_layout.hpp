#pragma once

#include <string>

class VerticalLayout;

class AbsoluteLayout {
 public:
  bool Button(const std::string& text, int posX, int posY, int width = -1, int height = -1);
  void Label(const std::string& text, int posX, int posY, int width = -1, int height = -1);
  VerticalLayout NewVerticalLayout(int posX, int posY, int width, int height=-1);
};
