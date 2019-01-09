#include <cstdlib>
#include <iostream>
#include <vector>
// #include <chrono>

using std::vector;
using std::cin;
using std::cout;

//Find the maximum pairwise product from a list of numbers, i.e. 
//find the maximum product of any two numbers in that list.

long long MaxPairwiseProductFast(const vector<int>& numbers) {
  //auto start = std::chrono::high_resolution_clock::now(); //Begin stopwatch
  int n = numbers.size();
  int max_index1 = 0, max_index2 = 1;
  if (numbers[1] > numbers[0]){
    max_index1 = 1;
    max_index2 = 0;
  }
  for (int i = 2; i < n; ++i){ //Check for largest number
    if (numbers[i] > numbers[max_index2]){
      if (numbers[i] >= numbers[max_index1]){
	max_index2 = max_index1;
	max_index1 = i;
      }
      else {
	max_index2 = i;
      }
    }
  }
  /*auto finish = std::chrono::high_resolution_clock::now(); //Stop stopwatch
  std::chrono::duration<double> elapsed = finish-start; 
  std::cout << "Elapsed time: " << elapsed.count() << "sec\n";*/
  return ((long long)(numbers[max_index1])) * numbers[max_index2];
}

int main() {
  int n;
  cin >> n; //take in size of vector
  vector<int> numbers(n);
  for (int i = 0; i < n; ++i) {
    cin >> numbers[i]; //take in vector values
  }

  long long result = MaxPairwiseProductFast(numbers);
  cout << result << "\n";  
  return 0;
}
