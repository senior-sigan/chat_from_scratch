#include <raylib.h>

#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>

// class TextButton {
//  std::string text_;
// public:
//  explicit TextButton(const std::string& text): text_(text){}
//
//
//};

using namespace std;

bool isInside(const Vector2& target, const Rectangle& rect) {
  return target.x >= rect.x && target.x <= rect.x + rect.width && target.y >= rect.y &&
         target.y <= rect.y + rect.height;
}

template<typename TNumber>
float asFloat(TNumber num) {
  return static_cast<float>(num);
}

void Label(const std::string& text, int posX, int posY, int width = -1, int height = -1) {
  const int fontSize = 20;
  int margin = 5;
  if (width < 0) {
    width = MeasureText(text.c_str(), fontSize) + margin * 2;
  }
  if (height < 0) {
    height = fontSize + 2 * margin;
  }
  DrawRectangle(posX, posY, width, height, BLUE);
  DrawText(text.c_str(), posX + margin, posY + margin, fontSize, BLACK);
}

bool button(const std::string& text, int posX, int posY, int width = -1, int height = -1) {
  const int fontSize = 20;
  int margin = 5;

  const int txtWidth = MeasureText(text.c_str(), fontSize) + margin * 2;
  const int txtHeight = fontSize + 2 * margin;

  if (width < 0) {
    width = txtWidth;
  }
  if (height < 0) {
    height = txtHeight;
  }

  auto cursorPos = GetMousePosition();
  bool isHover = false;
  bool isClicked = false;
  if (isInside(cursorPos, Rectangle{asFloat(posX), asFloat(posY), asFloat(width), asFloat(height)})) {
    isHover = true;
    if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
      // TODO: track button id where mouse was pressed and released.
      // Current behaviour: we can press mouse somewhere and move it to the button and release.
      // This will fire onClick
      isClicked = true;
    }
  }

  if (isHover) {
    DrawRectangle(posX, posY, width, height, BLUE);
  } else {
    DrawRectangle(posX, posY, width, height, SKYBLUE);
  }

  // TODO: pos text in the middle of the rect

  int txtCenterX = (width - txtWidth) / 2;
  int txtCenterY = (height - txtHeight) / 2;


  DrawText(text.c_str(), posX + margin + txtCenterX, posY + margin + txtCenterY, fontSize, BLACK);

  return isClicked;
}

class CalcContext {
  const function<double(double, double)> saveLeft = [](double a, double b) { return a; };
  const function<double(double, double)> saveRight = [](double a, double b) { return b; };
  function<double(double, double)> operation = saveRight;

 public:
  double lhs = 0;
  double rhs = 0;

  void PrintState() const {
    cout << "LHS=" << lhs << ", RHS=" << rhs << endl;
  }

  double GetValue() const {
    //?????
    return 0;
  }

  void AddDigit(int d) {
    rhs = rhs * 10 + d;
  }

  void SetOperation(const function<double(double, double)>& func) {
    lhs = operation(lhs, rhs);
    operation = func;
    rhs = 0;
  }

  void CalcResult() {
    lhs = operation(lhs, rhs);
    rhs = 0;
    operation = saveLeft;
  }

  void Reset() {
    lhs = 0;
    rhs = 0;
    operation = saveRight;
  }
};

class ICalcButton {
 public:
  virtual void Act(CalcContext* ctx) = 0;
  virtual ~ICalcButton() = default;
};

class NumButton : public ICalcButton {
  const int num_;

 public:
  explicit NumButton(int num) : num_(num) {}

  void Act(CalcContext* ctx) override {
    ctx->AddDigit(num_);
  }
};

class AddButton : public ICalcButton {
 public:
  void Act(CalcContext* ctx) override {
    ctx->SetOperation([](double lhs, double rhs) { return lhs + rhs; });
  }
};
class MulButton : public ICalcButton {
 public:
  void Act(CalcContext* ctx) override {
    ctx->SetOperation([](double lhs, double rhs) { return lhs * rhs; });
  }
};
class SubButton : public ICalcButton {
 public:
  void Act(CalcContext* ctx) override {
    ctx->SetOperation([](double lhs, double rhs) { return lhs - rhs; });
  }
};
class DivButton : public ICalcButton {
 public:
  void Act(CalcContext* ctx) override {
    ctx->SetOperation([](double lhs, double rhs) { return lhs / rhs; });
  }
};
class ResultButton : public ICalcButton {
 public:
  void Act(CalcContext* ctx) override {
    ctx->CalcResult();
  }
};
class ResetButton : public ICalcButton {
 public:
  void Act(CalcContext* ctx) override {
    ctx->Reset();
  }
};

class DotButton : public ICalcButton {
 public:
  void Act(CalcContext* ctx) override {
    cout << "Not implemented" << endl;
  }
};

int main() {
  const int startXAt = 10;
  const int btnWidth = 50;
  const int btnHeight = 50;
  const int margin = 5;
  const int btnCol = 4;
  const int btnRows = 5;

  const int labelY = 10;
  const int labelHeight = 50;
  const int labelWidth = (btnWidth + margin) * btnCol -  margin;

  const int startYAt = labelY + labelHeight + margin;

  const int screenWidth = startXAt + btnWidth * btnCol + margin*(btnCol-1) + startXAt;
  const int screenHeight = labelY + btnHeight * btnRows + margin*(btnRows-1) + labelY + labelHeight + margin;

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
  return 0;
}
