#include "hw2_functions.h"

bool sortFunc(Creature a, Creature b) {
  return (a.width * a.height) < (b.width * b.height);
}

int main() {
  // stores all the cards currently collected
  Creature cards[150];

  // get cards from random creatures and store them in cards array
  // at each step, check if we can go home
  int i = 0;
  while (i < 150) {

    Creature currentCreature = getRandomCreature();
    std::cout << currentCreature.name << ": " << getRandomSaying() << std::endl;

    cards[i] = currentCreature;

    std::sort(cards, cards + i, sortFunc);

    if (canLeave(cards, i)) {
      std::cout << "You can finally go home!!!" << std::endl;
      return 0;
    } else {
      std::cout << "press ENTER to continue";
      std::cin.get();
      i++;
    }
  }

  std::cout << "You're stuck here forever" << std::endl;

  return 0;
}
