#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <cmath>
#include <random>

using std::vector;
using std::pair;

vector<int> optimal_points(vector<pair<int,int>> &segments) {
  vector<int> points;

  std::sort(segments.begin(),segments.end(),[](const pair<int,int> &left, const pair<int,int> &right){
      return left.second < right.second;
    });
  int leftestright = segments[0].second;
  points.push_back(leftestright);

  for (size_t i = 0; i < segments.size(); ++i) {
    if(segments[i].first<=leftestright){
      continue;
    }
    else{
      leftestright = segments[i].second;
      points.push_back(leftestright);
    }
  }
  return points;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<pair<int,int>> segments(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> segments[i].first >> segments[i].second;
  }
  
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
  std::cout << std::endl;
}
/*
int main() {
    int n = 100, s, e;
    std::set<int> sset, eset;
    // std::cin >> n;
    // for (int i = 0; i < n; ++i) {
        // std::cin >> s >> e;
        // sset.insert(s); eset.insert(e);
    // }
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(0,pow(10,9));
    for (int i=0; i<n; ++i){
        s = dis(gen);
        std::uniform_int_distribution<> newdis(s,pow(10,9));
        e = newdis(gen);
        sset.insert(s); eset.insert(e);
    } 
    std::vector<int> starts(sset.begin(),sset.end());
    std::vector<int> ends(eset.begin(),eset.end());

    vector<int> points = optimal_points(starts,ends);
    std::cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i) {
        std::cout << points[i] << " ";
    }
}
*/
