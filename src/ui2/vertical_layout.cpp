#include "vertical_layout.hpp"
Position ui2::VerticalLayout::AddWidget(int width, int height) {
  Position pos = pos_;
  pos_.y += height;
  return pos;
}
