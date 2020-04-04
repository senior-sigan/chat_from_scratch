#include "absolute_layout.hpp"
#include "ui.hpp"
#include "vertical_layout.hpp"

bool AbsoluteLayout::Button(const std::string& text, int posX, int posY, int width, int height) {
  return ui::Button(text, posX, posY, width, height);
}
void AbsoluteLayout::Label(const std::string& text, int posX, int posY, int width, int height) {
  return ui::Label(text, posX, posY, width, height);
}
VerticalLayout AbsoluteLayout::NewVerticalLayout(int posX, int posY, int width, int height) {
  return VerticalLayout(posX, posY, width, height);
}
