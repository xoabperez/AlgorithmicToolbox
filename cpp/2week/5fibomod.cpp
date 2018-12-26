#include <iostream>
// Compute F(n) modulo m, where F(n) is the nth number
// of the Fibonacci sequence, and n may be very large.

// Solution: note that F(i)mod(m) for varying i and fixed m
// produces a periodic sequence that begins with 0 1 ...
// So once the length of this period is found, F(n)mod(m)
// is not far off

//See fibonacci_huge.py for notes
int get_fibonacci_huge(long long n, int m) {
    if (n <= 1)
        return n;

    int previous = 0;
    int tmp_previous;
    int current  = 1;
    long long index = 0LL;
    
    while(true) {
        tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%m;
        index++;
        if ((previous%m == 0) && (current%m == 1)){
            break;
        }   
    }

    previous = 0;
    current  = 1;
    index = n%index;

    if(index == 0){
      return 0;
    } else if(index == 1){
      return 1;
    } else {
      for(int i = 1; i<index; i++){
        tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%m;
      }
    }
    return current;
}

int main() {
    long long n;
    int m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge(n, m) << '\n';
}
