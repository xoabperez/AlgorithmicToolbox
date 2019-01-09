#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
    vector<int> summands;
    int index = 1;
    while(true){
        if(n <= (2*index)){
            summands.push_back(n);
            break;
        }
        else{
            summands.push_back(index);
            n -= index;
            index += 1;
        }
    }
    return summands;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> summands = optimal_summands(n);
    std::cout << summands.size() << '\n';
    for (size_t i = 0; i < summands.size(); ++i) {
        std::cout << summands[i] << ' ';
    }
}
