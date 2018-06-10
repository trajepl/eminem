#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct compare {
    bool operator()(const pair<int, int> &l, const pair<int, int> &r) {
        return l.second > r.second;
    }
};

int main() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> q;
    q.push(make_pair(1,2));
    q.push(make_pair(1,1));
    q.push(make_pair(1,3));
    q.push(make_pair(2,2));

    while(!q.empty()) {
        cout << q.top().first << " " << q.top().second << endl;
        q.pop();
    }
    return 0;
}
