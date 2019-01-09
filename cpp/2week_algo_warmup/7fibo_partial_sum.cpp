#include <iostream>
// Find the last digit of a partial sum of Fibonacci numbers,
// F(m)+F(m+1)+...+F(n). We can find the last digit of the sum to
// F(n) and carefully subtract the last digit of the sum to F(m-1)

int fibosum(long long n){
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

long long get_fibonacci_partial_sum(long long from, long long to) {
  if (to <= 1){
    return to;
  }
  int first, last;
  first = fibosum(from-1);
  last = fibosum(to);
  return ((last-first+10)%10);
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum(from, to) << '\n';
}
