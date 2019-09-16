#include <iostream>
#include <string>

using std::string;

#define max(a,b) ((a) > (b) ? (a) : (b))

int stress_test = 0;

int edit_distance(const string &str1, const string &str2) {

  int m = str1.size(), n = str2.size();
  int distances[m+1][n+1], previous[m+1][n+1][2];

  // Fill out first row/column with index
  for (int i = 0; i <= m; i++){
    distances[i][0] = i; // "Deletion" of first string
  }
  for (int j = 0; j <= n; j++){
    distances[0][j] = j; // "Insertion" into first string
  }

  int i = 0, j = 0;
  // Fill out rest of matrices
  for (int k = 0; k < (m*n); k++){

    i = (k/n) + 1;
    j = (k % n) + 1;
    // Initialize with distance of insertion 
    distances[i][j] = distances[i][j-1] + 1;
    previous[i][j][0] = i;
    previous[i][j][1] = j-1;

    // Deletion
    if ((distances[i-1][j] + 1) < distances[i][j]){
      distances[i][j] = distances[i-1][j] + 1;
      previous[i][j][0] = i-1;
      previous[i][j][1] = j;
    }

    // Match
    if (distances[i-1][j-1] < distances[i][j] && (str1[i-1] == str2[j-1])){
      distances[i][j] = distances[i-1][j-1];
      previous[i][j][0] = i-1;
      previous[i][j][1] = j-1;
    }

    // Mismatch
    if ((distances[i-1][j-1] + 1) < distances[i][j] && (str1[i-1] != str2[j-1])){
      distances[i][j] = distances[i-1][j-1] + 1;
      previous[i][j][0] = i-1;
      previous[i][j][1] = j-1;

    }
  }

  // Show matrices 
  if(stress_test){
    for (int i = 1; i <= m; i++){
      for (int j = 1; j <= n; j++){
	std::cout << previous[i][j][0] << "," << previous[i][j][1] << " ";
      }
      std::cout << std::endl;
    }
    for (int i = 0; i <= m; i++){
      for (int j = 0; j <= n; j++){
	std::cout << distances[i][j] << " ";
      }
      std::cout << std::endl;
    }
  }
  return distances[m][n];
}

string gen_random(const int len){
  
  static const char alpha[] = "abcdefghijklmnopqrstuvwxyz" ;
  string s(len,0);
  for (int i = 0; i < len; i++){
    s[i] = alpha[rand() % (sizeof(alpha) - 1)];
  }
  return s;
}

int main() {

  string str1, str2;

  // For testing, generate random strings and check distance manually by
  // printing output
  if (stress_test){
      srand(time(NULL));
  
      int len1 = rand() % 10, len2 = rand() % 10;
      str1 = gen_random(len1);
      str2 = gen_random(len2);
  
      for (int i = 0; i < len1; i++){
	std::cout << str1[i] << " ";
      }
      std::cout << std::endl;
      for (int i = 0; i < len2; i++){
	std::cout << str2[i] << " ";
      }
      std::cout << std::endl;
  }
  // User input
  else{
    std::cin >> str1 >> str2;
  }

  // Shortcut for if a string is empty, distance is length of other
  if ((str1.size() == 0) || (str2.size() == 0)){
    std::cout << max(str1.size(), str2.size()) << std::endl;
  }
  else{
    std::cout << edit_distance(str1, str2) << std::endl;
  }

  return 0;
  
}
