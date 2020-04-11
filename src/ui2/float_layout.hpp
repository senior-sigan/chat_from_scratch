#pragma once

#include "i_layout.hpp"

namespace  ui2 {

class FloatLayout : public ILayout {
  const Position pos_;

 public:
  explicit FloatLayout(const Position& pos) : pos_(pos) {}
  Position AddWidget(int width, int height) override;
};

}