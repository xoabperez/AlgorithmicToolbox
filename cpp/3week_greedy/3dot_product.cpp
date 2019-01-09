#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <random>
#include <chrono>
// Implement an algorithm for the maximum advertising problem:
//   place most profitable ads in slots likely to get most clicks.
//
// Input: the number of ads (n), the profit per click of ad (a),
//   and the number of clicks per slot (b).
//
// Output: The maximal revenue

using std::vector;

long long max_dot_product(vector<int> a, vector<int> b) {
  long long result = 0;
  std::sort(a.begin(),a.end());
  std::sort(b.begin(),b.end());
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
