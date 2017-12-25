#include <iostream>
#include <vector>

using namespace std;

#define MAX_VAL  ((unsigned)(-1)>>1)

vector<vector<int>> graph(int n, vector<vector<int>> &edges) {
    vector<vector<int>> graph(n+1, vector<int>(n+1, MAX_VAL));
    for(auto &edge: edges) {
        graph[edge[0]][edge[1]] = edge[2];
        graph[edge[1]][edge[0]] = edge[2];
    }   
    return graph;
}

int closest_node(vector<vector<int>> &graph, int n) {
    int lowcost = MAX_VAL;
    int node = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(lowcost > graph[i][j]) {
                node = i;
                lowcost = graph[i][j];
            }
        }
    }
    return node;
}

void prim(vector<vector<int>> &graph, vector<vector<int>> &T, int n) {      
    int node = closest_node(graph, n);
    vector<int> cost(n+1), src_node(n+1, 0);

    for(int i = 1; i <= n ; i++) {
        cost[i] = graph[node][i];
        src_node[i] = node;
    }

    cost[node] = 0;
    for(int i = 1; i <= n; i++) {
        int mincost = MAX_VAL, minnode = 0;
        for(int j = 1; j <= n; j++) {
            if(cost[j] < mincost && cost[j] != 0) {
                mincost = cost[j];
                minnode = j;
            }
        }
        T.push_back({src_node[minnode], minnode});
        cost[minnode] = 0;
        for(int j = 1; j <= n; j++) {
            if(graph[minnode][j] < cost[j]) {
                cost[j] = graph[minnode][j];
                src_node[j] = minnode;
            }
        }
    }
}

void test(int n, vector<vector<int>> edges) {
    vector<vector<int>> g = graph(n, edges);
    vector<vector<int>> ret;
    prim(g, ret, n);

    for(auto &edge: ret)
        cout << edge[0] << " " << edge[1] << endl;
}


int main() {
    int n = 6;
    vector<vector<int>> edges = {{1, 2, 100}, {1, 4, 30}, {1, 5, 45},
                                 {2, 3, 50}, {2, 5, 40}, {2, 6, 25},
                                 {3, 5, 35}, {3, 6, 15}, {4, 6, 20}};
    for(auto &edge: edges) 
        cout << edge[0] << " -> " << edge[1] << ": " << edge[2] << endl;
    test(n, edges);

    cout << "----------" << endl;
    n = 5;    
    edges = {{1, 2, 10}, {1, 4, 30}, {1, 5, 45}, {2, 3, 50}, {2, 5, 40}, 
             {3, 5, 35}, {4, 5, 20}};
    for(auto &edge: edges) 
        cout << edge[0] << " -> " << edge[1] << ": " << edge[2] << endl;
    test(n, edges);

    cout << "----------" << endl;
    n = 5;    
    edges = {{1, 2, 10}, {1, 3, 30}, {1, 4, 45}, {2, 3, 50}, {2, 5, 40}, 
             {3, 5, 35}, {4, 5, 10}};
    for(auto &edge: edges) 
        cout << edge[0] << " -> " << edge[1] << ": " << edge[2] << endl;
    test(n, edges);

    return 0;
}
