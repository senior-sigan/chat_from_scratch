#pragma once

#include "calc_context.hpp"
#include <iostream>

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
    std::cout << "Not implemented" << std::endl;
  }
};