#ifndef HW2_FUNCTIONS_H
#define HW2_FUNCTIONS_H

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
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
  Creature() {
    name = "";
    width = 0;
    height = 0;
  }
};

std::string getRandomSaying();
Creature getRandomCreature();
bool canLeave(Creature cards[], int i);

#endif
