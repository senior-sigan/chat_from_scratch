#include "utils.hpp"

bool isInside(const Vector2& target, const Rectangle& rect) {
  return target.x >= rect.x && target.x <= rect.x + rect.width && target.y >= rect.y &&
      target.y <= rect.y + rect.height;
}
