/*

This program calculates the minimum number of coins necessary
to make change for a given value, assuming there are 3 
denominations worth 1 cent, 3 cents, and 4 cents.

*/

#include <iostream>
#include <algorithm>
#include <vector>
#define min(a, b) ((a) < (b) ? (a) : (b))

// This first implementation only uses 4 entries in an array.
// Since we're only counting the number of coins, we can just
// keep track of the number of coins it took to get the the
// most recent 4 values and calculate the next value from there
// (since the max value of a coin is 4.) for larger denominations
// we would need a larger vector.
int get_change_less_space(int m) {
  std::vector<int> table(4);
  int option1, option3, option4;
  table[0] = 0;
  table[1] = 1;
  table[2] = 2;
  table[3] = 1;
  
  for (int i = 4; i <= m; i++)
    {
      option1 = table[3]+1; // Using 1-cent coin
      option3 = table[1]+1; // Using 3-cent coin
      option4 = table[0]+1; // Using 4-cent coin
      // Can get rid of first entry, rotate and fill the end
      std::rotate(table.begin(), table.begin()+1, table.end());
      table[3] = min(option1, min(option3, option4));
    }
  return table[3];
}

// This implementation doesn't use any time rotating, instead
// it just fills the next entry in the vector until reaching
// the entry we're interested in. 
int get_change_less_time(int m) {
  std::vector<int> table(m+1);
  int option1, option3, option4;
  table[0] = 0;
  table[1] = 1;
  table[2] = 2;
  table[3] = 1;
  
  for (int i = 4; i <= m; i++)
    {
      option1 = table[i-1]+1;
      option3 = table[i-3]+1;
      option4 = table[i-4]+1;
      table[i] = min(option1, min(option3, option4));
    }
  return table[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change_less_space(m) << '\n';
}
