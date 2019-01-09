#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <random>

using std::vector;
using std::string;
using std::pair;
using std::min;

void printvector(vector<pair<int,int>> &vec){
  for (size_t i = 0; i < vec.size(); i++) {
    std::cout << "(" << vec[i].first << "," << vec[i].second << ")\n";
  }
}

double distance(pair<int,int> &xy1, pair<int,int> &xy2, bool tf = 0){
  if(tf){
    std::cout << "Distance check \n";
    std::cout << "   (" << xy1.first << "," << xy1.second << ")\n";
    std::cout << "   (" << xy2.first << "," << xy2.second << ")\n";
  }
  int ydist = xy2.second-xy1.second;
  int xdist = xy2.first-xy1.first;
  return std::sqrt(pow(ydist,2)+pow(xdist,2));
}

double naive(vector<pair<int,int>> &xy){
  double dmin = distance(xy[0], xy[1],0);
  for(size_t i = 0; i < xy.size(); i++){
    for(size_t j = i+1; j < xy.size(); j++){
      dmin = min(dmin, distance(xy[i], xy[j], 0));
    }
  }
  return dmin;
}

double minmerge(vector<pair<int,int>> &xy, int left, int right, double d){
  int n = right-left;
  if(n == 2) return distance(xy[left], xy[left+1]);
  
  vector<pair<int,int>> central;
  int ave = left+n/2; //index used to split data
  double x_ave = xy[ave].first; //x value at split
  int dist_to_center; //check for each point
  for(int i = left; i < right ; i++){
    dist_to_center = std::abs(x_ave-(double)xy[i].first)-.0001; //tolerance
    if(dist_to_center < d){
      central.push_back(xy[i]);
    }
  }
  
  std::sort(central.begin(), central.end(), [](const pair<int,int> &left, const pair<int,int> &right){
	return left.second < right.second;
      }); // Sort according to y
    
  int elements_compare;
  double dmin = d;
  for(size_t i = 0; i < central.size(); i++){
    elements_compare = min(i+7, central.size());
    for(int j = i+1; j < elements_compare; j++){
      dmin = min(dmin, distance(central[i], central[j]));
    }
  }
  return dmin;
}

double minimal_distance(vector<pair<int,int>> &xy, int left, int right){
  if(left+1 == right) return 2*pow(10,9); //Single point
  
  int ave = left+(right-left)/2; //Split data
  double d1, d2, d, dmin;
  d1 = minimal_distance(xy, left, ave); //Find d for left
  d2 = minimal_distance(xy, ave, right); //Find d for right
  d = min(d1, d2); //Take d as minimum distance
  dmin = minmerge(xy, left, right, d); //Check points near center
  
  return dmin;
}

int main() {
  /*
  for(int test = 0; test < 10000; test++){
    size_t n = 100;
    vector<pair<int,int>> points(n);
  
    std::random_device rd;  //Will be used to obtain a seed 
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine 
    std::uniform_int_distribution<> dis(-pow(10,4),pow(10,4));
  
    for (size_t i = 0; i < n; i++) { // Fill x and y data randomly
      points[i].first = dis(gen);
      points[i].second = dis(gen);
    }
    
    std::sort(points.begin(),points.end(),[](const pair<int,int> &left, const pair<int,int> &right){
	return left.first < right.first;
      }); // Sort according to x for recursive routine splitting
    //printvector(points);
    double algo =  minimal_distance(points, 0, points.size());
    double quad = naive(points);
    if(std::abs(algo-quad) > .001){
      std::cout << "Algo: " << algo << " Naive: " << quad << "\n";
      //printvector(points);
    }
  }
  */
  size_t n;
  std::cin >> n;
  vector<pair<int,int>> points(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> points[i].first >> points[i].second;
  }
  std::sort(points.begin(),points.end(),[](const pair<int,int> &left, const pair<int,int> &right){
      return left.first < right.first;
    });
  
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(points, 0, points.size()) << "\n";
}
