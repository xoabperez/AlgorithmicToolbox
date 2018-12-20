#include <iostream>
#include<algorithm>

//Find the greatest common denominator by Euclid's
//algorithm. Very similar to code in python, see gcd.python
//for notes
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

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd(a, b) << std::endl;
  return 0;
}
