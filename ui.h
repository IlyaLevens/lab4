#ifndef UI_H
#define UI_H
#include <iostream>

int map_func(int& e) {
    e *= 2;
    return e;
}

bool where_func(int& e) {
    return e % 2 == 0;
}

void printMenu() {
  std::cout << "Choose an operation:\n";
  std::cout << "1. Insert element\n";
  std::cout << "2. Delete element\n";
  std::cout << "3. Balance the tree\n";
  std::cout << "4. Apply the 'where' function\n";
  std::cout << "5. Create a subgraph\n";
  std::cout << "6. Copy to string\n";
  std::cout << "7. Show the tree\n";
  std::cout << "8. Run tests\n";
  std::cout << "0. Exit\n";
}



#endif
