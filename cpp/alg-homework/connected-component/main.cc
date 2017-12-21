#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> graph(int n, vector<vector<int>> &edges) {
    vector<vector<int>> graph(n+1, vector<int>(n+1, 0));
    for(auto &edge: edges) {
        graph[edge[0]][edge[1]] = 1;
        graph[edge[1]][edge[0]] = 1;
    }   
    return graph;
}

void art(int u, int v, int n, vector<vector<int>> &G, vector<vector<pair<int, int>>> &result,
         vector<int> &dfn, vector<int> &l, stack<pair<int, int>> &s, int depth) {
    dfn[u] = l[u] = depth;
    for (int i = 1; i <= n; i++) {
        if (G[u][i] == 0) continue;
        if (i != v && dfn[i] < dfn[u])
            s.emplace(u, i);
        if (dfn[i] == 0) {
            art(i, u, n, G, result, dfn, l, s, depth+1);
            if (l[i] >= dfn[u]) {
                result.emplace_back();
                pair<int, int> p;
                do {
                    p = s.top(); s.pop();
                    result.back().push_back(p);
                } while (p != make_pair(u, i) && p != make_pair(i, u));
            }
            l[u] = min(l[u], l[i]);
        }
        else if (i != v) {
            l[u] = min(l[u], dfn[i]);
        }
    }
    return;
}

int main() {
    int n = 10;
    vector<vector<int>> edges = {{1, 2}, {1, 4}, {2, 3}, {2, 5}, {2, 7}, {2, 8},
                                 {3, 4}, {3, 9}, {3,10}, {5, 6}, {5, 7}, {5, 8},
                                 {7, 8}};

    vector<vector<int>> G = graph(n, edges);

    vector<vector<pair<int, int>>> result;
    vector<int> dfn(n+1, 0), l(n+1, 0);
    stack<pair<int, int>> s;
    art(1, 0, n, G, result, dfn, l, s, 1);

    for (int i = 0; i < result.size(); i++) {
        cout << "biconnected component #" << i << ":" << endl;
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j].first << "," << result[i][j].second << endl;
    }
    return 0;
}
