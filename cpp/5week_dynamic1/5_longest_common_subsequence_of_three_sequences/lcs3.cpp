#include <iostream>
#include <vector>

using std::vector;

// 0 for no stress test
// 1 for random stress test
// 2 for input stress test
int stress_test = 0;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {

  // Use the vector sizes to set up memoization array
  // We could use mxnx2 matrix but started with this
  auto m = a.size(), n = b.size(), o = c.size();
  int distances[m+1][n+1][o+1];

  // Fill out first row/col/depth with zeros
  for (size_t i = 0; i <= m; i++){
    for (size_t j = 0; j <= n; j++){
      distances[i][j][0] = 0;
    }
  }
  for (size_t j = 0; j <= n; j++){
    for (size_t k = 0; k <= o; k++){
      distances[0][j][k] = 0; 
    }
  }
  for (size_t i = 0; i <= m; i++){
    for (size_t k = 0; k <= o; k++){
      distances[i][0][k] = 0; 
    }
  }

  size_t i = 0, j = 0, k = 0;
  // Fill out rest of matrices
  for (size_t l = 0; l < (m*n*o); l++){

    // Instead of nested for loop, condense to one vector of size mxnxo
    i = (l % (m * n))/n + 1;  //row
    j = (l % n) + 1;          //col
    k = (l / (m * n)) + 1;

    // Check for match
    if ((a[i-1] == b[j-1]) && (a[i-1] == c[k-1])){
      distances[i][j][k] = std::max(distances[i-1][j-1][k-1]+1, distances[i][j][k-1]);
    }
    else {
      distances[i][j][k] = std::max(distances[i][j][k-1], distances[i][j-1][k]);
      distances[i][j][k] = std::max(distances[i][j][k], distances[i-1][j][k]);
    }
  }

  // Show matrices
  if(stress_test != 0){
    for (size_t i = 0; i <= o; i++){
      for (size_t j = 0; j <= m; j++){
	for (size_t k = 0; k <= n; k++){
	  std::cout << distances[j][k][i] << " ";
	}
	std::cout << std::endl;
      }
      std::cout << std::endl;
    }
  }

  return distances[m][n][o];
}

int main() {

  vector<int> a, b, c;
  
  // For testing, generate random strings and check distance manually by
  // printing output
  if (stress_test == 1){
      srand(time(NULL));

      size_t n = rand() % 100, m = rand() % 100, o = rand() % 100;
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

      for (size_t i = 0; i < o; i++) {
	c.push_back(rand() % 10);
	std::cout << c[i] << " ";
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

    size_t o;
    std::cin >> o;
    vector<int> temp_c(o);
    for (size_t i = 0; i < o; i++) {
      std::cin >> temp_c[i];
    }
    for (size_t i = 0; i < o; i++) {
      c.push_back(temp_c[i]);
    }
  }

  std::cout << lcs3(a, b, c) << std::endl;
}
