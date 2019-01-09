#include <iostream>
#include <vector>

//Find the nth number in the Fibonacci sequence. 

int fibonacci_fast(int n) {
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
    return fibo[n];
}

int main() {
    int n;
    std::cin >> n; 
    std::cout << fibonacci_fast(n);
    return 0;
}
