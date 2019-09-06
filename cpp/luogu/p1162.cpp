#include <iostream>
#include <queue>

using namespace std;

int graph[30][30] = {0};
int visited[30][30] = {0};
bool existed = false;
int pos[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
queue<pair<int, int>> res;

void bfs(int i, int j, int n) {
    queue<pair<int, int>> q;
    q.push(make_pair(i, j)); 
    bool is_cycle = true;
    while (!q.empty()) {
        pair<int, int> point = q.front();
        res.push(point);
        q.pop();
        for (int m = 0; m < 4; ++m) {
            int new_i = point.first + pos[m][0];
            int new_j = point.second + pos[m][1];
            if (new_i < 0 || new_i > n || new_j < 0 || new_j > n) {
                is_cycle = false;
            } else {
                if (visited[new_i][new_j] == 0 && graph[new_i][new_j] == 0) {
                    q.push(make_pair(new_i, new_j));
                    res.push(make_pair(new_i, new_j));
                    visited[new_i][new_j] = 1;
                }
            }
        }
    }
    if (is_cycle)
        existed = true;
    else
        res = queue<pair<int, int>>();
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (existed) {
                while (!res.empty()) {
                    pair<int, int> t = res.front();
                    res.pop();
                    graph[t.first][t.second] = 2;
                }
                for (int x = 0; x < n; ++x) {
                    for (int y = 0; y < n; ++y) {
                        cout << graph[x][y] << " ";
                    }
                    cout << endl;
                }
                return 0;
            }
            if (visited[i][j]) continue;
            if (graph[i][j] == 0) {
                visited[i][j] = 1;
                bfs(i, j, n);
            }
        }
    }
    return 0;
}

