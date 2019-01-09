#include <cstdlib>
#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

//Find the maximum pairwise product from a list of numbers, i.e. 
//find the maximum product of any two numbers in that list.
//Additionally, perform a 'stress test' of the algorithm by subjecting
//it to various random tests and comparing performance with the naive
//algorithm, which is known to be correct. 

long long MaxPairwiseProduct(const vector<int>& numbers) {
  //Checks for max product by multiplying every number by 
  //every other number (without repetition)
  long long result = 0;
  int n = numbers.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (((long long)(numbers[i])) * numbers[j] > result) {
        result = ((long long)(numbers[i])) * numbers[j];
      }
    }
  }
  return result;
}

long long MaxPairwiseProductFast(const vector<int>& numbers) {
  //Finds largest two numbers since these will produce the largest
  //product
  int n = numbers.size(); 

  int max_index1 = -1;
  for (int i = 0; i < n; ++i) //Check for largest number
    if ((max_index1 == -1) || (numbers[i] > numbers[max_index1]))
      max_index1 = i;

  int max_index2 = -1;
  for (int j = 0; j < n; ++j)  //Check for second largest number
    if ((j != max_index1) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2])))
      max_index2 = j;
  cout << max_index1 << ' ' << max_index2 << "\n";
  return ((long long)(numbers[max_index1])) * numbers[max_index2];
}

int main() {
  //Test many scenarios
  while (true) {
    int n = rand() % 3 + 2; //Take a random sized vector
    cout << n << "\n";
    vector<int> a;
    for (int i = 0; i < n; ++i) {
      a.push_back(rand() % 10); //Fill the vector with random numbers
    }
    for (int i = 0; i < n; ++i) {
      cout << a[i] << ' '; //Display vector
    }
    cout << "\n";
    //Compare the naive, but known to be correct, solution with
    //faster, less certain solution
    long long res1 = MaxPairwiseProduct(a);
    long long res2 = MaxPairwiseProductFast(a);
    if (res1 != res2) { 
      cout << "Wrong answer: " << res1 << ' ' << res2 << "\n";
      break;
    }
    else {
      cout << "OK\n";
    }
  }
}
