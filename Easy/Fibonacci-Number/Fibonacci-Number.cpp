#include "main.hpp"

class Solution {
public:
  int fib(int n) {
    if (0 == n or 1 == n){
      return n;
    }
    return fib(n - 2) + fib(n - 1);
  }
};

int main() {
  Solution sln;

  assert(1 == sln.fib(2));

  assert(2 == sln.fib(3));

  assert(5 == sln.fib(5));

  return 0;
}