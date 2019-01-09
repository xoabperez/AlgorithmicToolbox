#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <random>
#include <set>
#include <vector>
#include <string>
#include <sstream>
#include <chrono>

using std::vector;
using std::string;

int main(){
    auto start = std::chrono::high_resolution_clock::now();
    vector<int> a = {1,2,3};
    int left = 0, right = (int)a.size();
    std::cout << right;
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish-start;
    std::cout << "Elapsed time: " << elapsed.count() << "sec\n";
}