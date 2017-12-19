#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int Find(int x, vector<int> &src) {
    if(src[x] == 0) 
        return x;
    else 
        return src[x] = Find(src[x], src);
}

void Union(int x, int y, vector<int> &src) {
    x = Find(x, src);
    y = Find(y, src);
    if(x == y) return ;
    src[y] = x;
}

bool cmp(vector<int> &a, vector<int> &b) {
    return a[2] < b[2];
}

void kruskal(vector<vector<int>> &edges, vector<vector<int>> &T, int n) {
    sort(edges.begin(), edges.end(), cmp);
    vector<int> src(n+1, 0);

    for(auto &edge: edges) {
        int x = Find(edge[0], src);
        int y = Find(edge[1], src);
        if(x != y) {
            T.push_back(edge);
            Union(x, y, src);
        }
    }
}

int main() {
    int n = 6;
    vector<vector<int>> edges = {{1, 2, 100}, {1, 4, 30}, {1, 5, 45},
                                 {2, 3, 50}, {2, 5, 40}, {2, 6, 25},
                                 {3, 5, 35}, {3, 6, 15}, {4, 6, 20}};
    
    vector<vector<int>> ret;
    kruskal(edges, ret, n);
    for(auto &edge: ret)
        cout << edge[0] << " " << edge[1] << endl;

    return 0;
}
