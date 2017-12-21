#include <iostream>
#include <vector>
using namespace std;

void helper(int col, int n, vector<int> &pos, vector<vector<string>> &result,
            vector<bool> &flagRow, vector<bool> &flag45, vector<bool> &flag135) {
    if (col == n) {
        result.emplace_back(n, string(n, '.'));
        for (int i = 0; i < n; i++)
            result.back()[pos[i]][i] = 'Q';
        return;
    }
    for (int row = 0; row < n; row++) {
        if (!flagRow[row] && !flag45[row+col] && !flag135[row-col+n-1]) {
            pos[col] = row;
            flagRow[row] = flag45[row+col] = flag135[row-col+n-1] = true;
            helper(col+1, n, pos, result, flagRow, flag45, flag135);
            flagRow[row] = flag45[row+col] = flag135[row-col+n-1] = false;
        }
    }
    return;
}

vector<vector<string>> n_queens(int n) {
    vector<int> pos(n);
    vector<bool> flagRow(n, false), flag45(2*n-1, false), flag135(2*n-1, false);
    vector<vector<string>> result;
    helper(0, n, pos, result, flagRow, flag45, flag135);
    return result;
}

int main() {
    int n = 8;
    vector<vector<string>> result = n_queens(n);
    for (int i = 0; i < result.size(); i++) {
        cout << "answer #" << i << " for " << n << " queens: \n";
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << endl;
    }

    return 0;
}
