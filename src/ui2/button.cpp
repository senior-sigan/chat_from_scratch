#include <raylib.h>

#include "../utils.hpp"
#include "wigets.hpp"

bool ui2::Button(ILayout* layout, const std::string& text, int width, int height) {
  const int fontSize = 20;
  int margin = 5;

  const int txtWidth = MeasureText(text.c_str(), fontSize) + margin * 2;
  const int txtHeight = fontSize + 2 * margin;

  if (width < 0) {
    width = txtWidth;
  }
  if (height < 0) {
    height = txtHeight;
  }

  auto pos = layout->AddWidget(width, height);

  auto cursorPos = GetMousePosition();
  bool isHover = false;
  bool isClicked = false;
  if (isInside(cursorPos, Rectangle{asFloat(pos.x), asFloat(pos.y), asFloat(width), asFloat(height)})) {
    isHover = true;
    if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
      // TODO: track Button id where mouse was pressed and released.
      // Current behaviour: we can press mouse somewhere and move it to the Button and release.
      // This will fire onClick
      isClicked = true;
    }
  }

  if (isHover) {
    DrawRectangle(pos.x, pos.y, width, height, BLUE);
  } else {
    DrawRectangle(pos.x, pos.y, width, height, SKYBLUE);
  }

  // TODO: pos text in the middle of the rect

  int txtCenterX = (width - txtWidth) / 2;
  int txtCenterY = (height - txtHeight) / 2;

  DrawText(text.c_str(), pos.x + margin + txtCenterX, pos.y + margin + txtCenterY, fontSize, BLACK);

  return isClicked;
}