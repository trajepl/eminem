#include<iostream>
#include<vector>

using namespace std;

bool check(int row, vector<int> &idxqueue) {
    for(int i = 0; i < row; i++) {
        if(idxqueue[i] == idxqueue[row] || abs(idxqueue[i]-idxqueue[row]) == row-i)
            return false;
    }
    return true;
}

void helper(int n, vector<vector<string>> &ret, vector<int> &idxqueue, int row) {
    if(row == n) {
        vector<string> matrix;
        for(int i = 0; i < n; i++) {
            string tmp = "";
            for(int j = 0; j < n; j++) {
                if(idxqueue[i] == j)
                    tmp += "q";
                else tmp += ".";
            }
            matrix.emplace_back(tmp);
        }
        ret.emplace_back(matrix);
        return ;
    } 
    for(int i = 0; i < n; i++) {
        idxqueue[row] = i;
        if(check(row, idxqueue)) {
            helper(n, ret, idxqueue, row+1);
        }
    }
}

vector<vector<string>> queue(int n) {
    vector<vector<string>> ret;
    vector<int> idxqueue(n, -1);
    helper(n, ret, idxqueue, 0);
    return ret;
}

int main() {
    int n = 4;
    vector<vector<string>> rets = queue(n);
    
    for(auto &ret: rets) {
        for(auto &row: ret) {
            cout << row << endl;
        }
        cout << "-----------" << endl;
    }
    return 0;
}
