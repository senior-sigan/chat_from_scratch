#include <raylib.h>

#include "ui.hpp"
#include "utils.hpp"

using namespace std;

bool button(const std::string& text, int posX, int posY, int width, int height) {
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

  auto cursorPos = GetMousePosition();
  bool isHover = false;
  bool isClicked = false;
  if (isInside(cursorPos, Rectangle{asFloat(posX), asFloat(posY), asFloat(width), asFloat(height)})) {
    isHover = true;
    if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
      // TODO: track button id where mouse was pressed and released.
      // Current behaviour: we can press mouse somewhere and move it to the button and release.
      // This will fire onClick
      isClicked = true;
    }
  }

  if (isHover) {
    DrawRectangle(posX, posY, width, height, BLUE);
  } else {
    DrawRectangle(posX, posY, width, height, SKYBLUE);
  }

  // TODO: pos text in the middle of the rect

  int txtCenterX = (width - txtWidth) / 2;
  int txtCenterY = (height - txtHeight) / 2;

  DrawText(text.c_str(), posX + margin + txtCenterX, posY + margin + txtCenterY, fontSize, BLACK);

  return isClicked;
}