#include <iostream>
// Find the last digit of a sum of the first n Fibonacci
// numbers. Playing around with small values of n shows that
// the nth sum is equal to F(n+2)-1.

// We previously calculated the last number by adding numbers
// modulo 10, but adding 10^18 numbers will take too long.
// Instead, we can use n mod 10 to find the last digit and
// use program 5. The pisano period for m = 10 is 60.

int fibonacci_sum(long long n) {
  int previous = 0;
  int tmp_previous;
  int current  = 1;
  int index = (n+2)%60;

  for(int i = 1; i<index; i++){
    tmp_previous = previous;
    previous = current;
    current = (tmp_previous + current)%10;
  }
  if(current == 0){
    return 9;
  } else{
    return (current-1);
  }
}

int main() {
    long long n;
    std::cin >> n;
    std::cout << fibonacci_sum(n);
}
