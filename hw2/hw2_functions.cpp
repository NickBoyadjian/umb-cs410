#include "hw2_functions.h"

std::string creatureSayings[14] = {
    "Whazzup?",
    "Duuude, totally love the clown head and human body combo!",
    "Looking for a card (shark)?",
    "Are you someone famous?",
    "You look fishy to me; or are you clowning around?",
    "Don't trust the salmon!!!",
    "Here's some advice: the shark wants you to be his chum!",
    "Better take some paper towels if you visit the blobfish",
    "Hey man, got any sea-weed?",
    "Let me give you my card...my phone number is on the back",
    "I'd gladly pay you Tuesday for a lobster roll today.",
    "Don't be so crabby!",
    "Just keep swimming, swimmin, swimming, ...",
    "You just keep sinking, sinking, sinking,..."};

Creature creatures[14] = {Creature("Wanda Walrus", 2, 6),
                          Creature("Stanley Sardine", 3, 1),
                          Creature("Sylvia Seahorse", 4, 2),
                          Creature("Janie Jellyfish", 1, 10),
                          Creature("Doris Dolphin", 8, 4),
                          Creature("Bob Blobfish", 1, 5),
                          Creature("Sammy Shark", 8, 4),
                          Creature("Walter Whale", 6, 2),
                          Creature("Stevie Salmon", 2, 3),
                          Creature("Sheila Shellfish", 1, 3),
                          Creature("Daniel Octopus", 3, 7),
                          Creature("Mark Herrings", 9, 5),
                          Creature("Bernie Tuna", 3, 5),
                          Creature("Oscar Tilapia", 5, 3)

};

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

bool hasStack(Creature cards[], int i) {
  if (i < 5)
    return false;

  for (int j = 0; j < (i - 6); j++) {
    for (int k = 0; k < 6; k++) {
      if (!(cards[j + k].height <= cards[j + k + 1].height &&
            cards[j + k].height <= cards[j + k + 1].width &&
            cards[j + k].width <= cards[j + k + 1].height &&
            cards[j + k].width <= cards[j + k + 1].width &&
            (cards[j + k + 1].width > cards[j + k].width ||
             cards[j + k + 1].width > cards[j + k].height ||
             cards[j + k + 1].height > cards[j + k].width ||
             cards[j + k + 1].height > cards[j + k].height))) {
        std::cout << "nobueno";
        break;
      } else if (k >= 6) {
        printCards(cards, j, k);
        return true;
      }
    }
  }

  return false;
}

bool canLeave(Creature cards[], int i) {
  return hasAllCreatures(cards, i); // || hasStack(cards, i);
}
