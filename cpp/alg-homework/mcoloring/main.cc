#include<iostream>
#include<vector>

using namespace std;

vector<vector<bool>> graph(int n, vector<pair<int, int>> edges) {
    cout << "original graph: " << endl;
    vector<vector<bool>> g(n+1, vector<bool>(n+1, false));
    for(auto edge: edges) {
        cout << edge.first << " - " << edge.second << endl;
        g[edge.first][edge.second] = true;
        g[edge.second][edge.first] = true;
    }
    return g;
}

int nextcolor(int m,  vector<vector<bool>> g, vector<int> x, int k) {
    for(int i = x[k]+1; i < m; i++) {
        int j = 1;
        for(; j < g[k].size(); j++) 
            if(g[k][j] && k != j && i == x[j]) break;
        if(j == g[k].size()) return i; 
    }
    return -1;
}

void mcoloring(int m, vector<vector<bool>> g, vector<vector<int>> &ret, vector<int> x, int k) {
    int n = g.size() - 1;

    while(1) {
        x[k] = nextcolor(m, g, x, k);
        if(x[k] == -1) return ;
        if(k == n) {
            ret.emplace_back(x);
            
        } else {
            mcoloring(m, g, ret, x, k+1);
        }
    }
}

void test(int m, int n, vector<pair<int, int>> edges) {
    vector<vector<bool>> g = graph(n, edges);

    vector<vector<int>> ret;
    vector<int> x(n+1, -1);
    mcoloring(m, g, ret, x, 1);

    for(auto &anw: ret) {
        for(int i = 1; i < anw.size(); i++) {
            cout << anw[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 5, m = 4;
    vector<pair<int, int>> edges = {{1, 2}, {1, 3}, {1, 4}, 
                                    {2, 3}, {2, 4}, {2, 5},
                                    {3, 4}, {4, 5}};
    test(m, n, edges);
    
    m = 3;
    test(m, n, edges);

    m = 3; n = 4;
    edges = {{1, 2}, {1, 3}, {1, 4}, {2, 3}, {3, 4}};
    test(m, n, edges);
    return 0;
}
