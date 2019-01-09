#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>
#include <chrono>
#include <random>

using std::vector;

void printvector(vector<int> &a){
  for (size_t i = 0; i < a.size(); ++i) {
	std::cout << a[i] << ' ';
  }
  std::cout << std::endl;
}

int naive(vector<int> &a, int n) {
  vector<int> integers(pow(10,9),0);
  for(int i = 0; i < n; i++){
    integers[a[i]] += 1;
  }
  for(size_t i = 0; i < integers.size(); i++){
    if(integers[i] > n/2){
      return 1;
    }
  }
  return -1;
}

int merge(vector<int> &a, int left, int right, int ml, int mr){
  int n = right-left;
  //int ave = left + n/2;
  int count_ml = 0;
  int count_mr = 0;
  if(ml != -1){
    for(int i = left; i < right; i++){
      if(ml == a[i]){
	count_ml++;
      }
    }
  }
  if(mr != -1){
    for(int i = left; i < right; i++){
      if(mr == a[i]){
	count_mr++;
      }
    }
  }
  if(count_ml > n/2) return ml;
  if(count_mr > n/2) return mr;
  return -1;
}

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  int ave = left + (right-left)/2;
  int ml = get_majority_element(a, left, ave);
  int mr = get_majority_element(a, ave, right);
  int majority = merge(a, left, right, ml, mr);
  return majority;
}

int main() {
  /*
  for(int i = 0; i < 1; i++){
    int n = pow(10,5);
    vector<int> a(n);
    std::random_device rd;  //Seed for the random number engine
    std::mt19937 gen(rd()); //Mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(0,pow(10,9));
    for (size_t i = 0; i < (a.size()); ++i) {
      a[i] = dis(gen);
    }
    auto start = std::chrono::high_resolution_clock::now();
    bool algo = (get_majority_element(a, 0, a.size()) != -1);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish-start;
    std::cout << "Elapsed time: " << elapsed.count() << "sec\n";

    bool quadratic;
    quadratic = (naive(a, a.size()) != -1);
    std::cout << algo << std::endl;
    if(quadratic != algo){
      std::cout << "Algo: " << algo << " Quadratic: " << quadratic << std::endl;
      break;
    }
  }
  */
  
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
  
  return 0;
}
