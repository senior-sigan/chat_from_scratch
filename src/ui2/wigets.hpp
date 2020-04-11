#pragma once

#include <string>
#include "i_layout.hpp"

namespace ui2 {

bool Button(ILayout* layout, const std::string& text, int width=-1, int height=-1);

void Label(ILayout* layout, const std::string& text, int width = -1, int height=-1);

}