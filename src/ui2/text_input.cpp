#include <raylib.h>

#include "wigets.hpp"

void ui2::TextInput(ILayout* layout, std::stringstream& out, const std::string& place_holder, int width, int height) {
  int margin = 5;
  const int fontSize = 20;

  auto pos = layout->AddWidget(width, height);

  DrawRectangleLines(pos.x, pos.y, width, height, BLACK);

  if (IsKeyPressed(KEY_BACKSPACE)) {
    out.seekp(-1, std::ios_base::end);
  }
  if (IsKeyPressed(KEY_ENTER)) {
    // TODO: use ctrl+enter to do new line. Enter would be used to send a message.
    out << "\n";
  }
  auto key = GetKeyPressed();
  if (key != 0) {
    out << static_cast<char>(key);
  }

  int text_width = 0;
  if (out.str().empty()) {
    DrawText(place_holder.c_str(), pos.x + margin, pos.y + margin, fontSize, GRAY);
  } else {
    text_width = MeasureText(out.str().c_str(), fontSize);
    DrawText(out.str().c_str(), pos.x + margin, pos.y + margin, fontSize, BLACK);
  }

  if (static_cast<long>(GetTime()) % 2 == 0) {
    DrawLine(text_width + pos.x + margin, pos.y + margin, text_width + pos.x + margin, pos.y + margin + fontSize,
             BLACK);
  }
}