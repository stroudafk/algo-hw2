#include <iostream>
#include <vector>
#include "HW2.h"

int main() {
  // Q5
  std::cout << "Q5" << std::endl;
  std::cout << countFives(123467890) << std::endl;  // should output 0
  std::cout << countFives(555555) << std::endl;  // should output 6
  std::cout << countFives(15354) << std::endl;  // should output 2

  // Q6
  std::cout << "Q6" << std::endl;
  std::cout << pickTrees({1, 2, 3, 4, 5}) << std::endl;  // should output 9
  std::cout << pickTrees({1, 3, 4, 3}) << std::endl;  // should output 6
  std::cout << pickTrees({5, 1, 4, 9}) << std::endl;  // should output 14
}
