#include <iostream>
#include <vector>

using std::vector;

int partition3(vector<int> &A) {
  int sum = 0;
  int third;
  for (int i = 0; i < A.size(); i++){
    sum += A[i];
  }
  if ((sum % 3) != 0){
    return 0;
  }else{
    third = sum/3;
  }
  for (int i = 0; i < A.size(); i++){
    if (A[i] > third){
      return 0;
    }
  }

  
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
