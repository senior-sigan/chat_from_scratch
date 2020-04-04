#include "vertical_layout.hpp"

#include "ui.hpp"

VerticalLayout::VerticalLayout(const int pos_x, const int pos_y, const int width, const int height)
    : posX_(pos_x), posY_(pos_y), width_(width), height_(height) {}

bool VerticalLayout::Button(const std::string& text, int height) {
  auto posY = lastPosY_;
  if (height < 0) {
    lastPosY_ += 1;  // TODO: how to get button height?
  } else {
    lastPosY_ += height;
  }
  return ui::Button(text, posX_, posY, width_, height);
}

void VerticalLayout::NewLabel(const std::string& text, int height) {
  auto posY = lastPosY_;
  if (height < 0) {
    lastPosY_ += 1;  // TODO: how to get button height?
  } else {
    lastPosY_ += height;
  }
  return ui::Label(text, posX_, posY, width_, height);
}
int VerticalLayout::GetPosX() const {
  return posX_;
}
int VerticalLayout::GetPosY() const {
  return posY_;
}
int VerticalLayout::GetWidth() const {
  return width_;
}
void VerticalLayout::NewWidget(int height) {
  auto posY = lastPosY_;
  if (height < 0) {
    lastPosY_ += 1;  // TODO: how to get button height?
  } else {
    lastPosY_ += height;
  }
  ui::Widget(posX_, posY, width_, height);
}
