#include <iostream>
// Find the last digit of a sum of the first n Fibonacci
// numbers. Playing around with small values of n shows that
// the nth sum is equal to F(n+2)-1, and we previously solved how
// to calculate the last digit of F(m) 
int fibonacci_sum(long long n) {
    if (n <= 1)
        return n;
    int tmp_previous;
    int previous = 0;
    int current  = 1;
    
    for (long long i = 0; i < n+1; ++i) {
        tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%10;
    }

    return (current-1);
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum(n);
}
