#pragma once

#include <functional>
#include <iostream>

class CalcContext {
  const std::function<double(double, double)> saveLeft = [](double a, double b) { return a; };
  const std::function<double(double, double)> saveRight = [](double a, double b) { return b; };
  std::function<double(double, double)> operation = saveRight;

 public:
  double lhs = 0;
  double rhs = 0;

  void PrintState() const {
    std::cout << "LHS=" << lhs << ", RHS=" << rhs << std::endl;
  }

  double GetValue() const {
    //?????
    return 0;
  }

  void AddDigit(int d) {
    rhs = rhs * 10 + d;
  }

  void SetOperation(const std::function<double(double, double)>& func) {
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