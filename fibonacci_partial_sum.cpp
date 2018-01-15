#include <iostream>
// Find the last digit of a partial sum of Fibonacci numbers,
// F(m)+F(m+1)+...+F(n). We can find the last digit of the sum to
// F(n) and carefully subtract the last digit of the sum to F(m-1)

long long get_fibonacci_partial_sum(long long from, long long to) {
    if (to <= 1)
        return to;
    
    int tmp_previous;
    int previous = 0;
    int current  = 1;

    for (int i = 0; i < from; ++i) {
        tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%10;
    }
    int first = current;
    for (int i = 0; i < (to - from + 1); ++i) {
        tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%10;
    }

    return ((current-first+8)%10);
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum(from, to) << '\n';
}
