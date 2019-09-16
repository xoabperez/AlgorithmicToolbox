#include <iostream>
#include <vector>
#include <algorithm>

#define min(a,b) ((a) < (b) ? (a) : (b))

using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  // Initialize to large number so when compared to others, will change
  std::vector<int> number_operations(n+1,100000), previous_value(n+1);

  // Will never go to 0; just set 1 and 2
  number_operations[1] = 0;
  number_operations[2] = 1;
  previous_value[1] = 0;
  previous_value[2] = 1;

  // Start memoization
  for (int i = 3; i <= n; i++){
    // First check if it's divisible by 3, use that previous value
    if (i % 3 == 0) {
      number_operations[i] = number_operations[i/3] + 1;
      previous_value[i] = i/3;
    }
    // If divisible by two and number operations is less than for 3
    if (i % 2 == 0) {
      if (number_operations[i/2] < number_operations[i]){
	  number_operations[i] = number_operations[i/2] + 1;
	  previous_value[i] = i/2;
      }
    }
    // Finally, check if adding 1 to previous is best option
    if ((number_operations[i-1]+1) < number_operations[i]){      
	number_operations[i] = number_operations[i-1]+1;
	previous_value[i] = i-1;
    }
  }

  // Write sequence going back down the chain
  while (n > 0) {    
    sequence.push_back(n);
    n = previous_value[n];
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
