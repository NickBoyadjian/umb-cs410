#include "hw3_calculator.h"

Fraction::Fraction(int n, int d) {
  m_Numerator = n;
  m_Denominator = d;
}

std::string Fraction::toString() {
  std::string res = "(" + std::to_string(this->getNumerator());
  res += " / ";
  res += std::to_string(this->getDenominator()) + ")";
  return res;
}

Fraction* Fraction::operator+ (const Fraction& rhs) {
  int n = (m_Numerator * rhs.m_Denominator) + (rhs.m_Numerator * m_Denominator);
  int d = rhs.m_Denominator * m_Denominator;

  Fraction *res = new Fraction(n, d);

  while (res->getDenominator() % 2 == 0 && res->getNumerator() % 2 == 0) {
    res->setNumerator(res->getNumerator() / 2);
    res->setDenominator(res->getDenominator() / 2);
  }

  return res;
}

Fraction* Fraction::operator- (const Fraction& rhs) {
  int n = (m_Numerator * rhs.m_Denominator) - (rhs.m_Numerator * m_Denominator);
  int d = rhs.m_Denominator * m_Denominator;

  Fraction *res = new Fraction(n, d);

  while (res->getDenominator() % 2 == 0 && res->getNumerator() % 2 == 0) {
    res->setNumerator(res->getNumerator() / 2);
    res->setDenominator(res->getDenominator() / 2);
  }

  return res;
}

Fraction* Fraction::operator* (const Fraction& rhs) {
  int n = m_Numerator * rhs.m_Numerator;
  int d = rhs.m_Denominator * m_Denominator;

  Fraction *res = new Fraction(n, d);

  while (res->getDenominator() % 2 == 0 && res->getNumerator() % 2 == 0) {
    res->setNumerator(res->getNumerator() / 2);
    res->setDenominator(res->getDenominator() / 2);
  }

  return res;
}

Fraction* Fraction::operator/ (const Fraction& rhs) {
  Fraction* new_rhs = new Fraction(rhs.m_Denominator, rhs.m_Numerator);
  return *this * *new_rhs;
}