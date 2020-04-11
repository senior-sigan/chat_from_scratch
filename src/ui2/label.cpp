#include "wigets.hpp"

#include <raylib.h>

void ui2::Label(ILayout* layout, const std::string& text, int width, int height) {
  const int fontSize = 20;
  int margin = 5;
  if (width < 0) {
    width = MeasureText(text.c_str(), fontSize) + margin * 2;
  }
  if (height < 0) {
    height = fontSize + 2 * margin;
  }

  auto pos = layout->AddWidget(width, height);

  DrawRectangle(pos.x, pos.y, width, height, BLUE);
  DrawText(text.c_str(), pos.x + margin, pos.y + margin, fontSize, BLACK);
}
