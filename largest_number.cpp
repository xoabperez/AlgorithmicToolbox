#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using std::vector;
using std::string;

int checkgreater(int x, int maxd){
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
        if(bi <= llast){
            return lil;
        }
    }
    return big;
}

string largest_number(vector<int> a) {
  //write your code here
  std::stringstream ret;
  while(!a.empty()){
      int maxd = 0;
      int index = 0;
      for(size_t i = 0; i < a.size(); ++i){
          maxd = checkgreater(maxd,a[i]);
          if(a[i] == maxd){
              index = i;
          }
      }
      a.erase(a.begin()+index);
      ret << maxd;
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
