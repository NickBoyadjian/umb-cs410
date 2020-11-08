#ifndef HW3_CALCULATOR_H
#define HW3_CALCULATOR_H

#include <iostream>
#include <string>
#include <queue>

class Fraction {
  private:
  int m_Numerator;
  int m_Denominator;

  public:
  Fraction* operator+ (const Fraction& rhs);
  Fraction* operator- (const Fraction& rhs);
  Fraction* operator* (const Fraction& rhs);
  Fraction* operator/ (const Fraction& rhs);
  int getNumerator() { return m_Numerator; }
  int getDenominator() { return m_Denominator; }
  void setNumerator(int x) { m_Numerator = x; }
  void setDenominator(int x) { m_Denominator = x; }
  Fraction(int n, int d);
  std::string toString();
};

// template <class T>
// enqueue(T t, queue<T> q) {
//   q->push(t);
// }


#endif