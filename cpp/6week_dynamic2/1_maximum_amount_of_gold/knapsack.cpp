#include <iostream>
#include <vector>

using std::vector;
int stress_test = 0;
int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int mem_array[2][W+1];

  for (int j = 0; j <= W; j++){
    mem_array[0][j] = 0;
  }
  mem_array[1][0] = 0;
  
  for (size_t i = 1; i <= w.size(); i++){
    for (int j = 1; j <= W; ++j){
      mem_array[1][j] = std::max(mem_array[0][j],
				 mem_array[1][j-1]);
      if (w[i-1] <= j){
	mem_array[1][j] = std::max(mem_array[1][j],
				   mem_array[0][j-w[i-1]] + w[i-1]);
      }
    }
    for (int j = 1; j <= W; ++j){
      mem_array[0][j] = mem_array[1][j];
      if(stress_test){
	std::cout << mem_array[0][j] << " ";
      }
    }
    if(stress_test){ std::cout << std::endl; }
  }

  return mem_array[1][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
