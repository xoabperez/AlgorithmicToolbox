#include <iostream>
#include <vector>

using std::vector;

void print_vec(vector<int> &A){

  for (size_t i = 0; i < A.size(); i++){
    std::cout << A[i] << " ";
  }
  std::cout << std::endl;
}

bool is_sum(int n, vector<int> &A, int round) {
  size_t Asize = A.size();

  // Going from 0 to n, see if values in the vector add up to something
  bool sum_matrix[n+1][A.size()+1];

  // Keep track of max to take it out first during first round
  int max_value = 0;
  if (round == 1){
    for (size_t j = 0; j < A.size(); j++){
      if (A[j] > max_value){
	max_value = A[j];
      }
    }
  }
  
  for (int i = 0; i <= n; i++){
    sum_matrix[i][0] = 0;
  }
  
  // Can make zero with any number, so set first row to ones
  for (size_t j = 0; j <= Asize; j++){
      sum_matrix[0][j] = 1;
  }

  for (int i = 1; i <= n; i++){
    for (size_t j = 1; j <= Asize; j++){
      // If values up to j can add to i
      sum_matrix[i][j] = sum_matrix[i][j-1];

      // If current value can be added to other value to sum to i
      if (A[j-1] <= i){
	sum_matrix[i][j] = sum_matrix[i][j] || sum_matrix[i-A[j-1]][j-1];
      }
      //std::cout << sum_matrix[i][j] << " ";
    }
    //std::cout << std::endl;
  }


  if (sum_matrix[n][Asize] == 1){

    if (round == 1){
      int m = max_value;
      vector<int> values_to_remove;
      
      n -= m;    
      values_to_remove.push_back(max_value);

      while (n > 0){
	for (size_t j = 1; j <= Asize; j++){
	  if (sum_matrix[n][j] == 1){
	    values_to_remove.push_back(n);
	    n -= A[j-1];
	    break;
	  }
	}

	size_t vsize = values_to_remove.size();
	for(size_t i = 0; i < vsize; i++){
	  for (size_t j = 0; j < A.size(); j++){

	    if (A[j] == values_to_remove[0]){
	      A.erase(A.begin()+j);
	      values_to_remove.erase(values_to_remove.begin());
	      break;
	    }  // if	      
	  } // for
	} // for
	
      } // while n > 0
    } // if round == 1
    return 1;
  } // if matrix[n][j] == 1
  else{
    return 0;
  }
}

bool partition3(vector<int> &A) {
  int sum = 0;
  int third;
  
  for (size_t i = 0; i < A.size(); i++){
    sum += A[i];
  }
  
  if ((sum % 3) != 0){
    /*std::cout << "Sum is " << sum << std::endl;
      std::cout << "Not divisible by 3" << std::endl;*/
    return 0;
  }
  else{
    third = sum/3;
  }
  
  for (size_t i = 0; i < A.size(); i++){
    if (A[i] > third){
      std::cout << "A value is larger than a third" << std::endl;
      return 0;
    }
  }
  
  if (is_sum(third, A, 1)){
    return is_sum(third, A, 2);
  }
  else{
    return 0;
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
