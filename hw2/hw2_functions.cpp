#include "hw2_functions.h"

std::string creatureSayings[14];
Creature creatures[14];

void getCreatures(Creature arr[]) {
  std::ifstream file;
  file.open("creatures.txt");
  for (int i = 0; i < 14; i++) {
    std::string fname;
    std::string lname;
    int w;
    std::string x;
    int h;
    file >> fname;
    file >> lname;
    file >> w;
    file >> x;
    file >> h;
    arr[i] = Creature(fname + " " + lname, w, h);
  }
  file.close();
}

void getSayings(std::string arr[]) {
  std::ifstream file;
  file.open("sayings.txt");
  for (int i = 0; i < 14; i++) {
    std::string saying;
    getline(file, saying);
    arr[i] = saying;
  }
}

void init() {
  getCreatures(creatures);
  getSayings(creatureSayings);
}

std::string getRandomSaying() {
  std::srand(time(NULL));
  return creatureSayings[rand() % 14];
}

Creature getRandomCreature() {
  std::srand(time(NULL));
  return creatures[rand() % 14];
}

bool hasAllCreatures(Creature cards[], int i) {
  for (int j = 0; j < 14; j++) { // go through every creature
    bool found = false;
    std::string name = creatures[j].name;
    for (int k = 0; k < i; k++) { // check if the creature is in cards
      if (name == cards[k].name) {
        found = true;
        break;
      }
    }
    if (found == false) {
      return false;
    }
  }
  std::cout << "Krusty now has cards from:" << std::endl;
  for (int i = 0; i < 15; i++) {
    std::cout << creatures[i].name << std::endl;
  }
  return true;
}

void printCards(Creature cards[], int i, int j) {
  std::cout << "winning cards:" << std::endl;

  for (; i < j; i++) {
    std::cout << cards[i].name << std::endl;
  }
}

// bool hasStack(Creature cards[], int i) {
//   if (i < 5)
//     return false;

//   for (int j = 0; j < (i - 6); j++) {
//     for (int k = 0; k < 6; k++) {
//       if (!(cards[j + k].height <= cards[j + k + 1].height &&
//             cards[j + k].height <= cards[j + k + 1].width &&
//             cards[j + k].width <= cards[j + k + 1].height &&
//             cards[j + k].width <= cards[j + k + 1].width &&
//             (cards[j + k + 1].width > cards[j + k].width ||
//              cards[j + k + 1].width > cards[j + k].height ||
//              cards[j + k + 1].height > cards[j + k].width ||
//              cards[j + k + 1].height > cards[j + k].height)) ||
//              !(cards[j + k].name == cards[j + k + 1].name)) {
//         break;
//       } else if (k >= 5) {
//         std::cout << "hello?" << std::endl << std::endl << std::endl;
//         printCards(cards, j, k);
//         return true;
//     }
//   }

//   return false;
// }

bool hasStack(Creature cards[], int length) {
  // loop 0 to length - 6
  // take next 6 distict cards into new array
  // if this new array follows the right rules
  // return true

  // if we never find true, return false

  for (int i = 0; i < length - 6; i++) {
    Creature newCards[6];
    newCards[0] = cards[i];
    int newCardsSize = 1;
    int offset = 1;
    while (newCardsSize < 6 && i + offset < length) {
      if (newCards[newCardsSize - 1].name != cards[i + offset].name) {
        newCards[newCardsSize++] = cards[i + offset];
      } else {
        offset++;
      }
    }
    if (newCardsSize == 6) {
      bool result = true;
      for (int j = 0; j < 5; j++) {
        if (!(newCards[j].height <= newCards[j + 1].height &&
              newCards[j].height <= newCards[j + 1].width &&
              newCards[j].width <= newCards[j + 1].height &&
              newCards[j].width <= newCards[j + 1].width &&
              ((newCards[j + 1].width > newCards[j].width) ||
               (newCards[j + 1].width > newCards[j].height) ||
               (newCards[j + 1].height > newCards[j].width) ||
               (newCards[j + 1].height > newCards[j].height)))) {
          result = false;
        }
      }
      if (result == true) {
        std::cout << std::endl << "You got a stack of 6:" << std::endl;

        for (int n = 0; n < 6; n++) {
          std::cout << newCards[n].name << newCards[n].name << " x "
                    << newCards[n].name << std::endl;
        }

        return true;
      };
    }
  }
  return false;
}

bool canLeave(Creature cards[], int i) {
  return hasAllCreatures(cards, i) || hasStack(cards, i);
}
