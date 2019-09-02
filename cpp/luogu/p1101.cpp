#include <iostream>
#include <string>
#include <vector>

using namespace std;

char grid[110][110] = {'*'};
int flag[110][110] = {0};
int direct[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
string std_str = "yizhong";

void dfs(vector<pair<int, int>> path, int i, int j, int mem, int std_k, int n) {
    if (std_k >= 7) {
        for (auto it: path) {
            flag[it.first][it.second] = 1;
        }
    }
    if (i < 0 || j < 0 || i >= n || j >= n) return ;

    if (grid[i][j] == std_str[std_k]) {
        path.push_back(make_pair(i, j));
        if (mem == -1) {
            for (int x = 0; x < 8; ++x) {
                dfs(path, i+direct[x][0], j+direct[x][1], x, std_k+1, n);
            } 
        } else {
            dfs(path, i+direct[mem][0], j+direct[mem][1], mem, std_k+1, n);
        }
        path.pop_back();
    } else {
        return;
    }
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    vector<pair<int, int>> path;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dfs(path, i, j, -1, 0, n);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (flag[i][j]) cout << grid[i][j];
            else cout << "*";
        }
        cout << endl;
    }
    
    return 0;
}
