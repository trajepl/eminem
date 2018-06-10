#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> getSkyLine(vector<vector<int>> &buildings) {
    vector<pair<int, int>> res;

    int i = 0;
    int x = 0, h = 0;
    int len = buildings.size();

    priority_queue<pair<int, int>> q;
    while(i < len || !q.empty()) {
        x = q.empty()?buildings[i][0]:q.top().second;
        if (i >= len || x < buildings[i][0]) {
            while (!q.empty() && x >= q.top().second) q.pop();
        } else {
            x = buildings[i][0];
            while (i < len && buildings[i][0] == x) {
                q.push(make_pair(buildings[i][2], buildings[i][1]));
                i++;
            }
        }

        h = q.empty()?0:q.top().first;
        if (res.empty() || res.back().second != h) {
            res.push_back(make_pair(x, h));
        }
    }
    return res;
}

int main() {
    vector<vector<int>> buildings = {
        {2, 9, 10}, {3, 7, 15}, {5, 12, 12},
        {15, 20, 10}, {19, 24, 8}};
    vector<pair<int, int>> res = getSkyLine(buildings);
    for(auto i: res) cout << i.first << " " << i.second << endl; 
    return 0;
}
