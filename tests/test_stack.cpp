#include <memory>
#include <stdexcept>

#include "TStack.h"

void check(bool condition) {
  if (!condition) {
    throw std::runtime_error("stack test failed");
  }
}

int main() {
  TStack<int> stack;
  check(stack.empty() && stack.size() == 0);

  stack.push(1);
  stack.push(2);
  stack.push(3);
  check(stack.size() == 3 && stack.top() == 3);
  stack.top() = 4;
  check(stack.pop() == 4);
  check(stack.pop() == 2);
  check(stack.pop() == 1);
  check(stack.empty());

  try {
    stack.pop();
    check(false);
  } catch (const std::out_of_range&) {
  }
  try {
    stack.top();
    check(false);
  } catch (const std::out_of_range&) {
  }

  stack.push(10);
  TStack<int> copy = stack;
  stack.clear();
  check(stack.empty() && copy.pop() == 10);

  TStack<std::unique_ptr<int>> move_only;
  move_only.push(std::make_unique<int>(42));
  check(*move_only.pop() == 42);
}
