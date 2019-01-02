#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  std::sort(segments.begin(),segments.end(),[](const Segment &left, const Segment &right){
      return left.end < right.end;
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
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
