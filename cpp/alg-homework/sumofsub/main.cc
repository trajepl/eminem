#include<iostream>
#include<vector>

using namespace std;

void helper(vector<int> vec, vector<vector<int>> &ret, vector<int> &w, int sum, int idx) {
    if(sum == 0 && idx >= vec.size()) {
        ret.emplace_back(w);
        return ;
    } 
    if(sum == 0) ret.emplace_back(w);
    for(int i = idx; i < vec.size(); i++) {
        w[i] = vec[i];
        helper(vec, ret, w, sum-vec[i], i+1);
        w[i]= -1;
    }
    
}

void test(int sum, vector<int> vec) {
    cout << "orginal array: ";
    for(auto ele: vec) 
        cout << ele << " ";
    cout << endl;

    vector<vector<int>> ret;
    vector<int> w(vec.size(), -1);
    helper(vec, ret, w, sum, 0);
    
    for(auto line: ret) {
        for(int i = 0; i < line.size(); i++) {
            if(line[i] >= 0) cout << line[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 10, 6, 7, 8, 9, 0};
    test(10, vec);
    test(9, vec);

    vec = {10, 8, 11, 7, 4};
    test(11, vec);
    return 0;
}
