#include <iostream>
// Find the last digit of the sum of the squares
// of the fibonacci numbers. We can multiply the last
// digit of n by the last digit of fibo(n+1).

int fibosum(long long n){
  int previous = 0;
  int tmp_previous;
  int current  = 1;
  int index = n%60;

  if(index == 0){
    return 0;
  }
  
  for(int i = 1; i<index; i++){
    tmp_previous = previous;
    previous = current;
    current = (tmp_previous + current)%10;
  }
  return current;
}

long long fibo_sum_square(long long n){
  if(n==0){
    return 0;
  }
  int side_a, side_b, area;
  side_a = fibosum(n);
  side_b = fibosum(n+1);
  area = side_a*side_b;
  return (area%10);
}

int main() {
  long long n;
  std::cin >> n; 
  std::cout << fibo_sum_square(n) << '\n';
}
