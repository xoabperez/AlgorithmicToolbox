#include <iostream>
#include <chrono>

//Find the last digit of the nth fibonacci number
//by only keeping track of last digit in all
//additions. See fibonacci_last_digit.py
int get_fibonacci_last_digit(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%10;
    }

    return current;
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit(n);
    std::cout << c << '\n';
    }
