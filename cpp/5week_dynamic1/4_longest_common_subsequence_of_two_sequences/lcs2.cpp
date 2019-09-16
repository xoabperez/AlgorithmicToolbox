#include <iostream>
#include <vector>

using std::vector;

// 0 for no stress test
// 1 for random stress test
// 2 for input stress test
int stress_test = 0;

int lcs2(vector<int> &a, vector<int> &b) {

  // Use the vector sizes to set up memoization array
  auto m = a.size(), n = b.size();
  int distances[m+1][n+1];

  // Fill out first row with zeros
  for (size_t i = 0; i <= m; i++){
    distances[i][0] = 0; 
  }
  for (size_t j = 0; j <= n; j++){
    distances[0][j] = 0; 
  }

  size_t i = 0, j = 0;
  // Fill out rest of matrices
  for (size_t k = 0; k < (m*n); k++){

    // Instead of nested for loop, condense to one vector of size mxn
    i = (k/n) + 1;   //row
    j = (k % n) + 1; //col
    
    // Check for match
    if (a[i-1] == b[j-1]){
      distances[i][j] = std::max(distances[i-1][j-1]+1, distances[i][j-1]);
    }
    else {
      distances[i][j] = std::max(distances[i][j-1], distances[i-1][j]);
    }
  }

  // Show matrices 
  if(stress_test != 0){
    for (size_t i = 0; i <= m; i++){
      for (size_t j = 0; j <= n; j++){
	std::cout << distances[i][j] << " ";
      }
      std::cout << std::endl;
    }
  }

  return distances[m][n];
}

int main() {

  vector<int> a, b;
  
  // For testing, generate random strings and check distance manually by
  // printing output
  if (stress_test == 1){
      srand(time(NULL));

      size_t n = rand() % 10, m = rand() % 10;
      for (size_t i = 0; i < n; i++) {
	a.push_back(rand() % 10);
	std::cout << a[i] << " ";
      }
      std::cout << std::endl;
      
      for (size_t i = 0; i < m; i++) {
	b.push_back(rand() % 10);
	std::cout << b[i] << " ";
      }
      std::cout << std::endl;
  }
  // User input
  else{
    size_t n;
    std::cin >> n;
    vector<int> temp_a(n);
    for (size_t i = 0; i < n; i++) {
      std::cin >> temp_a[i];
    }
    for (size_t i = 0; i < n; i++) {
      a.push_back(temp_a[i]);
    }
    
    size_t m;
    std::cin >> m;
    vector<int> temp_b(m);
    for (size_t i = 0; i < m; i++) {
      std::cin >> temp_b[i];
    }
    for (size_t i = 0; i < m; i++) {
      b.push_back(temp_b[i]);
    }
  }

  std::cout << lcs2(a, b) << std::endl;
}
