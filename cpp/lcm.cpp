#include <iostream>
#include <algorithm> 
// Finds the least common multiple of two numbers.
// For example, given 6 and 8, the LCM is 24. This is
// done by calculating the GCD of a and b, then taking
// a*b/GCD. 
int gcd(int a, int b) {
  int tempa = std::max(a,b);
  int tempb = std::min(a,b);
  while(tempb !=  0){
      a =tempa%tempb; 
      tempa = tempb;
      tempb = a;
  }
  
  return tempa;
}

long long lcm(int a, int b) {
  return (long long) a * b/gcd(a,b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm(a, b) << std::endl;
  return 0;
}
