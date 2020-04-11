#pragma once

#include "position.hpp"

namespace ui2 {

class ILayout {
 public:
  virtual Position AddWidget(int width, int height) = 0;
  virtual ~ILayout() = default;
};

}