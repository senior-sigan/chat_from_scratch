#pragma once

#include <raylib.h>

// TODO: do not use raylib Vector2 and Rectangle
bool isInside(const Vector2& target, const Rectangle& rect) {
  return target.x >= rect.x && target.x <= rect.x + rect.width && target.y >= rect.y &&
      target.y <= rect.y + rect.height;
}

template<typename TNumber>
float asFloat(TNumber num) {
  return static_cast<float>(num);
}