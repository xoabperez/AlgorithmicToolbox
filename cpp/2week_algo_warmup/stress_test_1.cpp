#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

//Find the nth number in the Fibonacci sequence. Test
//the fast algorithm versus the naive algorithm.

int fibonacci_naive(int n) {
    //Recursion formula
    if (n <= 1)
        return n;
    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int fibonacci_fast(int n) {
    auto start = std::chrono::high_resolution_clock::now();
    //Store the values in a vector and add 
    std::vector<int> fibo(n+1);
    fibo[0] = 0; 
    if (n>0){
        fibo[1] = 1;
    }
    if (n>1){
        for(int i=2; i<(n+1); i++){ 
            fibo[i] = fibo[i-1]+fibo[i-2];
        }    
    }
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish-start;
    std::cout << "Elapsed time: " << elapsed.count() << "sec\n";
    return fibo[n];
}

void test_solution() {
    //Test fast algorithm
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main() {
    int n;
    std::cin >> n; 
    std::cout << fibonacci_fast(n);
    test_solution();
    return 0;
}
