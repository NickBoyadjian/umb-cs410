#ifndef HW2_FUNCTIONS_H
#define HW2_FUNCTIONS_H

#include <cstdlib>
#include <ctime>
#include <string>

struct Creature {
  std::string name;
  int width;
  int height;
  Creature(std::string n, int w, int h) {
    name = n;
    width = w;
    height = h;
  }
};

std::string getRandomSaying();
Creature getRandomCreature();

#endif
