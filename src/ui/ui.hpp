#pragma once

#include <string>

namespace ui {

bool Button(const std::string& text, int posX, int posY, int width = -1, int height = -1);

void Label(const std::string& text, int posX, int posY, int width = -1, int height = -1);

void Widget(int posX, int posY, int width, int height);
}