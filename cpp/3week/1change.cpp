#include <iostream>

int get_change(int m) {
  int tens, fives, ones, n;
  tens = m/10;
  m = m%10;
  fives = m/5;
  m = m%5;
  n = tens+fives+m;
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
