#include <iostream>

#include "TStack.h"

int main() {
  TStack<int> stack;
  stack.push(10);
  stack.push(20);
  stack.push(30);

  while (!stack.empty()) {
    std::cout << stack.pop() << ' ';
  }
  std::cout << '\n';
}
