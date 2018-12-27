#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <set> 
#include <cmath>
#include <random>

using std::vector;

vector<int> optimal_points(vector<int> &s, vector<int> &e) {
    vector<int> points;
    size_t startind = 0, endind = 0;
    
    std::sort(s.begin(),s.end());
    std::sort(e.begin(),e.end());
    int leftestright = e[0];
    points.push_back(leftestright);

    for (size_t i = 0; i < s.size(); ++i) {
        if(s[startind]<=leftestright){
            startind +=1;
        }
        else{
            endind += 1;
            leftestright = e[endind];
            points.push_back(leftestright);
        }
        if(startind == s.size()){
            break;
        }
    }
    return points;
}

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
