#include "hw3_calculator.h"

template <class T>
void enqueue(std::queue<T*> &q, T* x) { q.push(x); }

template <class T>
void dequeue(std::queue<T*> &q) { q.pop(); }

template <class T>
T* peek(std::queue<T*> &q) { return q.front(); }

template <class T>
bool empty(std::queue<T*> &q) { return q.size() == 0; }

int main () {
  bool running = true;
  std::queue<Fraction*> results;
  while (running) {
    int n1, d1, n2, d2;
    char paren, slash, op;
    std::cout << "Enter your equation: ";
    std::cin >> paren >> n1 >> slash >> d1 >> paren;
    std::cin >> op;
    std::cin >> paren >> n2 >> slash >> d2 >> paren;

    Fraction* lhs = new Fraction(n1, d1);
    Fraction* rhs = new Fraction(n2, d2);
    Fraction* res;

    if (op == '+') {
      res = *lhs + *rhs;
    } else if (op == '-') {
      res = *lhs - *rhs;
    } else if (op == '*') {
      res = *lhs * *rhs;
    } else if (op == '/') {
      res = *lhs / *rhs;
    }

    enqueue(results, res);

    int choice;
    std::cout << std::endl << "Enter 0 to finish or 1 to continue: ";
    std::cin >> choice;
    std::cout << std::endl;
    if (choice == 0)
      running = false;
  }

  while (!empty(results)) {
    std::cout << (peek(results))->toString() << std::endl;
    dequeue(results);
  }

  return 0;
}