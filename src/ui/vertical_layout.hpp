#pragma once

#include <string>

class VerticalLayout {
  const int posX_;
  const int posY_;
  const int width_;
  const int height_;

  int lastPosY_ = 0;

 public:
  VerticalLayout(int pos_x, int pos_y, int width, int height);
  bool Button(const std::string& text, int height = -1);
  void NewLabel(const std::string& text, int height = -1);
  void NewWidget(int height);

  int GetPosX() const;
  int GetPosY() const;
  int GetWidth() const;
};
