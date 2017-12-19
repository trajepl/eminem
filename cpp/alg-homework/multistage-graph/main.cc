#include <iostream>
#include <vector>

using namespace std;

#define MAX_VAL ((unsigned)(-1) >> 1)

int multistage_graph(vector<vector<int>> &graph, vector<vector<int>> &dist) {
    vector<vector<int>> dp(1, vector<int>(graph[0].size(), 0));
    for (int k = 1; k < graph.size(); k++) {
        dp.emplace_back(graph[k].size(), MAX_VAL);
        for (int i = 0; i < graph[k].size(); i++) {
            for (int j = 0; j < graph[k-1].size(); j++) {
                int s = graph[k-1][j], t = graph[k][i];
                if (dist[s][t] == -1) continue;
                dp[k][i] = min(dp[k][i], dp[k-1][j] + dist[s][t]);
            }
        }
    }
    return dp.back()[0];
}

int main() {
    int n;
    vector<vector<int>> graph, d;

    n = 12;
    d = vector<vector<int>>(n+1, vector<int>(n+1, -1));
    graph = {{1}, {2, 3, 4, 5}, {6, 7, 8}, {9, 10, 11}, {12}};
    d[1][2] = 9; d[1][3] = 7; d[1][4] = 2; d[1][5] = 2;
    d[2][6] = 4; d[2][7] = 2; d[2][8] = 2;
    d[3][6] = 2; d[3][7] = 7;
    d[4][8] = 11;
    d[5][7] = 1; d[5][8] = 8;
    d[6][9] = 6; d[6][10] = 5;
    d[7][9] = 4; d[7][10] = 3;
    d[8][10] = 5; d[8][11] = 6;
    d[9][12] = 4; d[10][12] = 2; d[11][12] = 5;

    cout << "shortest path: " << multistage_graph(graph, d) << endl;
    return 0;
}
