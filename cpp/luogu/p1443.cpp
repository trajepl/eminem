#include <iostream>
#include <cstring>
#include <queue>
#include <iomanip>

using namespace std;

pair<int, int> start;
int graph[401][401];
int visited[401][401] = {0};
int pos[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2},\
    {1, 2}, {2, 1}, {2, -1}, {1, -2}};
queue<pair<int, int>> q;

void bfs(int n, int m) {
    q.push(start);
    while (!q.empty()) {
        pair<int, int> t = q.front(); q.pop();
        for (const auto& p: pos) {
            int i = t.first + p[0];
            int j = t.second + p[1];
            if (i < 0 || j < 0 || i >= n || j >=m) continue;
            if (!visited[i][j]) {
                q.push(make_pair(i, j));
                graph[i][j] = graph[t.first][t.second] + 1;
                visited[i][j] = 1;
            }
        }
    }
}

int main() {
    memset(graph, -1, sizeof(graph));
    int n, m; cin >> n >> m;
    cin >> start.first >> start.second;
    --start.first;
    --start.second;
    graph[start.first][start.second] = 0;
    visited[start.first][start.second] = 1;
    bfs(n, m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << left << setw(5) << graph[i][j];
        }
        cout << endl;
    }
    return 0;
}
