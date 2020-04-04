#include "calc.hpp"

#include <raylib.h>

#include <memory>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "../ui/ui.hpp"
#include "calc_buttons.hpp"
#include "calc_context.hpp"

using namespace std;

void RunCalc() {
  const int startXAt = 10;
  const int btnWidth = 50;
  const int btnHeight = 50;
  const int margin = 5;
  const int btnCol = 4;
  const int btnRows = 5;

  const int labelY = 10;
  const int labelHeight = 50;
  const int labelWidth = (btnWidth + margin) * btnCol - margin;

  const int startYAt = labelY + labelHeight + margin;

  const int screenWidth = startXAt + btnWidth * btnCol + margin * (btnCol - 1) + startXAt;
  const int screenHeight = labelY + btnHeight * btnRows + margin * (btnRows - 1) + labelY + labelHeight + margin;

  InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");

  SetTargetFPS(60);

  vector<string> btnTexts = {"",  "",  "",  "C", "7", "8", "9", "/", "4", "5",
                             "6", "*", "1", "2", "3", "-", "0", ".", "=", "+"};
  unordered_map<string, unique_ptr<ICalcButton>> btnActions{};
  btnActions["C"] = make_unique<ResetButton>();
  btnActions["7"] = make_unique<NumButton>(7);
  btnActions["8"] = make_unique<NumButton>(8);
  btnActions["9"] = make_unique<NumButton>(9);
  btnActions["/"] = make_unique<DivButton>();
  btnActions["4"] = make_unique<NumButton>(4);
  btnActions["5"] = make_unique<NumButton>(5);
  btnActions["6"] = make_unique<NumButton>(6);
  btnActions["*"] = make_unique<MulButton>();
  btnActions["1"] = make_unique<NumButton>(1);
  btnActions["2"] = make_unique<NumButton>(2);
  btnActions["3"] = make_unique<NumButton>(3);
  btnActions["-"] = make_unique<SubButton>();
  btnActions["0"] = make_unique<NumButton>(0);
  btnActions["."] = make_unique<DotButton>();
  btnActions["="] = make_unique<ResultButton>();
  btnActions["+"] = make_unique<AddButton>();

  CalcContext ctx;

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    stringstream ss;
    ss << ctx.lhs << " " << ctx.rhs;
    Label(ss.str(), startXAt, labelY, labelWidth, labelHeight);

    for (auto i = 0; i < btnTexts.size(); i++) {
      auto t = btnTexts[i];
      if (t.empty()) {
        continue;
      }
      int j = i / btnCol;
      int k = i % btnCol;
      int x = startXAt + k * (btnWidth + margin);
      int y = startYAt + j * (btnHeight + margin);
      if (button(t, x, y, btnWidth, btnHeight)) {
        // TODO: some magic!!!!
        btnActions.at(t)->Act(&ctx);
        ctx.PrintState();

        cout << "Pressed: " << t << endl;
      }
    }

    EndDrawing();
  }

  CloseWindow();
}