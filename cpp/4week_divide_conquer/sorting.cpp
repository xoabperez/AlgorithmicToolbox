#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>

using std::vector;
using std::swap;

/*void printvector(vector<int> &vec){
  for(size_t i = 0; i < vec.size(); i++){
    std::cout << vec[i] << ' ';
  }
  std::cout << std::endl;
}

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m = partition2(a, l, r);

  randomized_quick_sort(a, l, m - 1);
  randomized_quick_sort(a, m + 1, r);
}
*/
vector<int> partition3(vector<int> &a, int l, int r) {
  vector<int> m(2);
  int x = a[l];
  int j = l;
  int k = l+1;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] < x) {
      swap(a[i], a[k]);
      swap(a[k], a[j]);
      j++;
      k++;
    }
    else if (a[i] == x) {
      swap(a[i], a[k]);
      k++;
    }
  }
  m[0] = j;
  m[1] = k;
  return m;
}

void randomized_quick_sort3(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  vector<int> m = partition3(a, l, r);

  randomized_quick_sort3(a, l, m[0] - 1);
  randomized_quick_sort3(a, m[1], r);
}

int main() {
  /*
  for(int j = 0; j < 100; j++){
    int n = 100;
    vector<int> q(n), q3(n);
    std::random_device rd;  //Seed for the random number engine
    std::mt19937 gen(rd()); //Mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(1,10);
    for (size_t i = 0; i < (q.size()); ++i) {
      q[i] = dis(gen);
      q3[i] = q[i];
    }
    randomized_quick_sort(q, 0, q.size() - 1);
    randomized_quick_sort3(q3, 0, q3.size() - 1);
    for (size_t i = 0; i < q.size(); ++i) {
      if(q[i] != q3[i]){
	std::cout << "Quick : " << std::endl;
	printvector(q);
	std::cout << "Quick3: " << std::endl;
	printvector(q3);
	break;
      }
    }
  }
  */  
  
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort3(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
  
}
