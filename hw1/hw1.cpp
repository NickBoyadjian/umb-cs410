#include <iostream>

// Greeting ====================================================================
void printGreeting() {  
  std::cout << "Health-o-Matic Options" << std::endl;
}

void printOptions() {
  std::cout << "----------------------" << std::endl; 
  std::cout << "1. Taking a Walk!"      << std::endl;
  std::cout << "2. Your Medications"    << std::endl;
  std::cout << "3. Nap Time!!"          << std::endl;
  std::cout << "4. Caloric Intake"      << std::endl;
  std::cout << "5. Quit"                << std::endl;
  std::cout << std::endl;
}

int getOptionResponse() {
  char res;
  std::cin >> res;
  return res;
}

// Walk ========================================================================
int getNumberOfSteps(int legs) {
  int res = 1;
  for (int i = 1; i < legs + 1; i++) {
    res *= i;
  }
  return res;
}

void getNumberOfLegs(int* totalSteps) {
  std::cout << "How manymany legs do you have?" << std::endl;
  int legs;
  std::cin >> legs;
  if (legs <= 0) {
    std::cout << "ERROR: Number of legs must be a positive number" << std::endl;
    getNumberOfLegs(totalSteps);
  }
  *totalSteps = getNumberOfSteps(legs);
  std::cout << "Total number of steps = " << getNumberOfSteps(legs) << std::endl;
}

// Medications =================================================================
int getAnxietyLevel() {
  std::cout << "What is your anxiety level?" << std::endl;
  int res;
  std::cin >> res;
  if (res > 10 || res < 1) {
    std::cout << "ERROR: anxiety levels must be between 1 and 10" << std::endl;
    getAnxietyLevel();
  }
  return res;
}

int getDay() {
  std::cout << "What day of the week is it?" << std::endl;
  int res;
  std::cin >> res;
  if (res > 7 || res < 1) {
    std::cout << "ERROR: day must be between 1 and 7" << std::endl;
    getDay();
  }
  return res;
}

int getNumberOfPills(int anxietyLevel, int day) {
  return anxietyLevel - day > 0 ? anxietyLevel - day : 0;
}

void printPills(int* numberOfPills) {
  int day = getDay();
  int anxietyLevel = getAnxietyLevel();
  int pills = getNumberOfPills(anxietyLevel, day);
  *numberOfPills = pills;
  std::cout << "You should take " << pills << " pills." << std::endl;
} 

// Sleep =======================================================================
int getHoursSlept() {
  std::cout << "How many hours did you sleep last night?" << std::endl;
  int hours;
  std::cin >> hours;
  if (hours < 0) {
    std::cout << "Your sleep must be a positive number" << std::endl;
    getHoursSlept();
  }
  return hours;
}

int getLengthOfNap(int steps, int pills, int hoursSlept) {
  return hoursSlept + steps / (pills == 0 ? 1 : pills);
}

void printNapTime(int length) {
  std::cout << "You should nap for " << length << " minutes" << std::endl;
}

// Calories ====================================================================
int getCalories(int steps) {
  int weight;
  int height; 
  float temp;
  std::cout << "What is your weight?" << std::endl;
  std::cin >> weight;
  std::cout << "What is your height?" << std::endl;
  std::cin >> height;
  std::cout << "What is the room temperature?" << std::endl;
  std::cin >> temp;
  if (height < 1 || weight < 1) {
    std::cout << "ERROR: height and weight must be positive numbers" << std::endl;
    getCalories(steps);
  }
  if (weight > 800) {
    std::cout << "ERROR: weight can't be over 800lbs" << std::endl;
    getCalories(steps);
  }
  return 6 * weight + 2 * height + 1 / temp + steps;
}

void printCalories(int cals) {
  std::cout << "Calories: " << cals << std::endl;
}

int main() {
  int totalSteps = -1;
  int numberOfPills = -1;
  
  while (true) {
    printGreeting();
    printOptions();
    char choice = getOptionResponse();

    
    switch (choice) {
      case '1' : getNumberOfLegs(&totalSteps);
                 break;
      case '2' : printPills(&numberOfPills);
                 break;
      case '3' : {
        if (totalSteps == -1 || numberOfPills == -1) {
          std::cout << "ERROR: You first need to calculate your steps and pills taken." << std::endl;
          break;
        }
        printNapTime(getLengthOfNap(totalSteps, numberOfPills, getHoursSlept()));
        break;
      }
      case '4' : {
        if (totalSteps == -1) {
          std::cout << "ERROR: You first need to calculate your steps." << std::endl;
          break;
        }
        printCalories(getCalories(totalSteps));
        break;
      }
      case '5' : std::cout << "See you next time!" << std::endl; 
                 return 0;
    }
  }
}
