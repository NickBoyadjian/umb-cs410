#include "hw3_calculator.h"

int main () {
  Fraction* one = new Fraction(3, 4);
  Fraction* two = new Fraction(7, 4);
  Fraction* three = *one / *two;
  std::cout << three->toString() << std::endl;
  return 0;
}