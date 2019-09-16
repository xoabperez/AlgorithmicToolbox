#include <iostream>
#include <cassert>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::max;
using std::min;

int stress_test = 1;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

void print_square_matrix(int *matrix, int size)
{
  
  for(int i = 0; i < size*size; i++)
    {
      std::cout << matrix[i] << " ";
      if ((i+1) % size == 0)
	{
	  std::cout << std::endl;
	}
    }
}

long long get_maximum_value(const string &exp) {
  int str_length = exp.size();
  int n = (str_length+1)/2;
  int min_values[n*n], max_values[n*n];
  int j;
  
  for (int i = 0; i < n*n; i++)
    {
      min_values[i] = 0;
      max_values[i] = 0;
    }
  for (int i = 0; i < n; i++)
    {
      min_values[n*i+i] = exp[2*i] - '0';
      max_values[n*i+i] = exp[2*i] - '0';
    }

  for (int l = 2; l <= n; l++)
    {
      for (int i = 0; i < (n-l); i++)
	{
	  j = i+l;
	  for(int k = i; k < j; k++)
	    {
	      
	      if (stress_test)
		{
		  std::cout << "i,k,j " << i << "," << k << "," << j << std::endl;
		}
	    }
	}
    }


  if (stress_test)
    {
      print_square_matrix(min_values, n);
      print_square_matrix(max_values, n);
    }
  
  return 0;
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
