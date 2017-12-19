#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define MAX_VAL ((unsigned)(-1) >> 1)

vector<vector<pair<int, int>>> graph(int n, vector<vector<int>> &edges) {
    vector<vector<pair<int, int>>> g(n+1);
    for(auto &edge: edges) {
        g[edge[0]].push_back({edge[1], edge[2]});
        g[edge[1]].push_back({edge[0], edge[2]});
    }   
    return g;
}

int dijkstra(vector<vector<pair<int, int>>> &graph, vector<int> &path, int s, int t, int n) {
    vector<int> dist(n+1, MAX_VAL);
    vector<bool> visited(n+1, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    
    dist[s] = 0;
    que.push({0, s});
    while(!que.empty()) {
        int tmp = que.top().second;
        que.pop();

        if(visited[tmp]) continue;
        visited[tmp] = true;
        for(auto &edge: graph[tmp]) {
            int v = edge.first, w = edge.second;
            if(dist[v] > dist[tmp] + w) {
                dist[v] = dist[tmp] + w;
                path[v] = tmp;
                que.push({dist[v], v});
            }
        }
    }
    return dist[t];
}

vector<int> print_path(int s, int t, vector<int> &path) {
    if(s == t) return vector<int>(1, s);
    vector<int> path_t = print_path(s, path[t], path);
    path_t.push_back(t);
    return path_t;
}

int main() {
    int n = 6, s = 1, t = 6;
    vector<vector<int>> edges = {{1, 2, 100}, {1, 4, 30}, {1, 5, 45},
                                 {2, 3, 50}, {2, 5, 40}, {2, 6, 25},
                                 {3, 5, 35}, {3, 6, 15}, {4, 6, 20}};
    
    vector<vector<pair<int, int>>> g = graph(n, edges);
    vector<int> path(n+1);

    dijkstra(g, path, s, t, n);
    vector<int> path_s = print_path(s, t, path);

    for(auto node: path_s)
        cout << node << " ";
    cout << endl;

    return 0;
}
