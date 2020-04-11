#pragma once

#include <raylib.h>

// TODO: do not use raylib Vector2 and Rectangle
bool isInside(const Vector2& target, const Rectangle& rect);

template<typename TNumber>
float asFloat(TNumber num) {
  return static_cast<float>(num);
}