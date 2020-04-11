#include <raylib.h>

#include "ui2/float_layout.hpp"
#include "ui2/vertical_layout.hpp"
#include "ui2/wigets.hpp"

int test_ui2() {
  //  RunCalc();
//  RunChat();
  int screenWidth = 800;
  int screenHeight = 600;
  InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");
  SetTargetFPS(30);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    ui2::VerticalLayout vertical({5, 5});
    ui2::Label(&vertical, "Hello");
    ui2::Label(&vertical, "World");
    ui2::Label(&vertical, "LONG TEXT IN english!!?");

    ui2::FloatLayout floating({300, 42});
    ui2::Label(&floating, "FlOaT!11");

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
