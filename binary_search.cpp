#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
// Implement the binary search algorithm that allows searching
// sorted lists. 
//
// Input: an integer n followed by sequence of n sorted numbers
//   The following line contains an integer k and k integers to 
//   be searched for
// Output: A sequence with the index of the kth integer in the list,
//   if found, and -1 otherwise
//See binary_search.py for details
using std::vector;
int bsearch(const vector<int> &a, int x, int left, int right){
    if((right-left)==1){
        return -1;
    }
    int mid = (right+left)/2;
      if(x==a[mid]){
          return mid;
      }
      else if(x<a[mid]){
          return bsearch(a,x,left,mid);
      }
      else{
          return bsearch(a,x,mid,right);
      }
}
int binary_search(const vector<int> &a, int x) {
  int right = (int)a.size(); 
  if(x<a.front() || x > a.back()){
      return -1;
  }
  if(x==a.front()){
      return 0;
  }
  if(x==a.back()){
      return (right-1);
  }
  return bsearch(a,x,0,right-1);
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  auto start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < m; ++i) {
    std::cout << linear_search(a, b[i]) << ' ';
  }
  auto finish = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = finish-start;
  std::cout << "Elapsed time: " << elapsed.count() << "sec\n";
  start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < m; ++i) {
    std::cout << binary_search(a, b[i]) << ' ';
  }
  finish = std::chrono::high_resolution_clock::now();
  elapsed = finish-start;
  std::cout << "Elapsed time: " << elapsed.count() << "sec\n";
}
