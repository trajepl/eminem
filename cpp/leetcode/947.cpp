#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <unordered_map>

using namespace std;

// dfs
int removeStones(vector<vector<int>>& stones) {
    int n = stones.size();
    vector<set<int>> graph = vector<set<int>>(n, set<int>());
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            graph[i].insert(j);
            graph[j].insert(i);
        }
    }
    int ans = 0;
    vector<bool> visited = vector<bool>(n, false);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            stack<int> s = stack<int>();
            s.push(i);
            visited[i] = true;
            ans--;

            while (!s.empty()) {
                int row_t = s.top(); s.pop();
                ans++;
                for (auto& col: graph[row_t]) {
                    if (!visited[col]) {
                        s.push(col);
                        visited[col] = true;
                    }
                }
            }
        }
    }
    return ans;    
}

// union-find
unordered_map<int, int> s;
int islands = 0;

int find(int x) {
    if (!s.count(x)) s[x] = x, islands++;
    if (x != s[x]) s[x] = find(s[x]);
    return s[x];
}

void uni(int x, int y) {
    int x1 = find(x), y1 = find(y);
    if (x1 != y1) s[x1] = y1, islands--;
}

int removeStonesUF(vector<vector<int>> &stones) {
    for (int i = 0; i < stones.size(); ++i) {
        uni(stones[i][0], ~stones[i][1]);
    }
    return stones.size() - islands;    
}
