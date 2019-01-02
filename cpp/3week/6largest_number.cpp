#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using std::vector;
using std::string;

int checkgreater(int x, int maxd){
  if(x==maxd){return x;}
  int big = std::max(x,maxd);
  int lil = std::min(x,maxd);
  string b = std::to_string(big);
  string l = std::to_string(lil);
  int blen = b.size(); 
  int llen = l.size();
  int llast = lil%10;
  for(int i = 0; i < llen; ++i){
    int bi = ((char)b[i])-'0';
    int li = ((char)l[i])-'0';
    if(bi > li){
      return big;
    }
    else if(bi < li){
      return lil;
    }
  }
  for(int i = llen; i < blen; ++i){
    int bi = ((char)b[i])-'0';
    if(bi < llast){
      return lil;
    }
  }
}

void largest_number(vector<int> a) {
  std::stringstream ret;
  while(!a.empty()){
    int maxd = -1;
    int index = 0;
    for(size_t i = 0; i < a.size(); ++i){
      maxd = checkgreater(a[i],maxd);
      if(a[i] == maxd){
	index = i;
      }
    }
    a.erase(a.begin()+index);
    std::cout << maxd;
  }
}

int main() {

  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  largest_number(a);

  /*  int n = 10, amax = 1000;
  vector<int> a(n);

  std::random_device rd;  //Will be used to obtain a seed for the random number engine
  std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
  std::uniform_int_distribution<> dis(0,amax);
  for(int j=0; j<10; ++j){
    for (int i=0; i<n; ++i){
      a[i] = dis(gen);
      std::cout << a[i] << " ";
    }
    std::cout << "    ";
    a[0] = 0;
    a[1] = 1000;
    std::cout << largest_number(a) << std::endl;
    }*/
}
