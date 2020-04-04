#include "ui.hpp"

#include <raylib.h>

#include <string>

using namespace std;

void Label(const string& text, int posX, int posY, int width, int height) {
  const int fontSize = 20;
  int margin = 5;
  if (width < 0) {
    width = MeasureText(text.c_str(), fontSize) + margin * 2;
  }
  if (height < 0) {
    height = fontSize + 2 * margin;
  }
  DrawRectangle(posX, posY, width, height, BLUE);
  DrawText(text.c_str(), posX + margin, posY + margin, fontSize, BLACK);
}