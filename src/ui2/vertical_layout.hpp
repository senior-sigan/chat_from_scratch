#pragma once

#include "i_layout.hpp"
namespace ui2 {

class VerticalLayout: public ILayout {
  const Position initial_pos_;
  Position pos_;
 public:
  explicit VerticalLayout(const Position& pos) : initial_pos_(pos), pos_(pos) {}
  Position AddWidget(int width, int height) override;
};

}