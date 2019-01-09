#include <iostream>
#include <vector>
#include <random>

using std::vector;
/*
void printvector(vector<int> &vec){
  for(size_t i = 0; i < vec.size(); i++){
    std::cout << vec[i] << ' ';
  }
  std::cout << std::endl;
}

long long naive(vector<int> &a, size_t left, size_t right){
  long long inversions = 0;
  for(size_t i = left; i < right; i++){
    for(size_t j = i+1; j < right; j++){
      if(a[j] < a[i]){
	inversions++;
      }
    }
  }
  return inversions;
}
*/
long long  merge(vector<int> &a, vector<int> &b, size_t left, size_t right){
  long long inversions = 0;
  int ave = left + (right - left) / 2;
  int j = 0; // Starting point for left array
  int k = 0; // Starting point for right array
  int maxj = ave-left; // Size of left array
  int maxk = right-ave; // Size of right array

  // While either array is empty, compare
  while(j < maxj && k < maxk){
    if(a[left+j] <= a[ave+k]){
      b[left+j+k] = a[left+j];
      j++;
    }
    else{
      b[left+j+k] = a[ave+k];
      inversions += ave-left-j;
      k++;
    }
  }
  // After going through either array completely, fill with other
  if(j < maxj){
    for(int i = j; i < maxj; i++){
      b[left+i+maxk] = a[left+i];
    }
  }
  if(k < maxk){
    for(int i = k; i < maxk; i++){
      b[left+maxj+i] = a[ave+i];
    }
  }
  // Transfer to original array
  for(size_t i = left; i < right; i++){
    a[i] = b[i];
  }
  
  return inversions;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  number_of_inversions += merge(a, b, left, right);
  return number_of_inversions;
}

int main() {
  /*
  for(int j = 0; j < 1; j++){
    int n = std::pow(10,5);
    vector<int> algo(n), simp(n), empty(n);
    std::random_device rd;  //Seed for the random number engine
    std::mt19937 gen(rd()); //Mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(1,std::pow(10,9));
    for (size_t i = 0; i < (algo.size()); ++i) {
      algo[i] = dis(gen);
      simp[i] = algo[i];
    }
    int i1 = get_number_of_inversions(algo, empty, 0, algo.size());
    int i2 = naive(simp, 0, simp.size());
    if (i1 != i2){
      std::cout << "algo = " << i1 << " naive = " << i2 << std::endl;
    }
  }
  */
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
  
}
