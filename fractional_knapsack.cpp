#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <random>
#include <chrono>
// Implement an algorithm for the fractional knapsack problem: finding
// the most valuable combination of items out of a larger pool 
// that can fit into a smaller bag.

// Input: The total number of items n, the capacity W of a knapsack,
//   and then for the next n lines, the value and weight of items.
//
// Output: The maximal value of fractions of items that fit
// 
// See fractional_knapsack.cpp for details
using std::vector;
using std::map;
using std::multimap;

std::pair<double,int> flip(std::pair<int, double> p){
    return std::pair<double,int>(p.second,p.first);
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    double value = 0.0;
    int index = 0;
    map<int,double> s;
    multimap<double,int> st;
    
    for(size_t i = 0; i<weights.size(); i++){
        s[i] = static_cast<double>(values[i])/weights[i];
    }
    std::transform(s.begin(),s.end(),std::inserter(st,st.begin()),flip);
    multimap<double,int>::reverse_iterator it;
    for (it=st.rbegin(); it!=st.rend(); ++it){
        if(capacity>0){
            int amt = std::min(capacity, weights[(*it).second]); 
            value += (*it).first*amt;
            capacity -= amt;
            index +=1;
        }
        else{
            break;
        }
    }    
    
    return value;
}

int main() {
    // int n;
    // int capacity;
    // std::cin >> n >> capacity;
    // vector<int> values(n);
    // vector<int> weights(n);
    // for (int i = 0; i < n; i++) {
        // std::cin >> values[i] >> weights[i];
    // }
    auto start = std::chrono::high_resolution_clock::now();
    
    int n = 1000,capacity = 2*pow(10,6);
    vector<int> values(n);
    vector<int> weights(n);

    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(0,capacity);
    for (int i=0; i<n; ++i){
        values[i] = dis(gen);
        weights[i] = dis(gen);
    } 
    
    double optimal_value = get_optimal_value(capacity, weights, values);

    std::cout.precision(10);
    std::cout << optimal_value << std::endl;
    
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish-start;
    std::cout << "Elapsed time: " << elapsed.count() << "sec\n";
    return 0;
}
