#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

string a, b;
unordered_map<string, vector<string>> rule;
unordered_map<string, int> mem;

void bfs() {
    queue<pair<string, int>> q;
    q.push(make_pair(a, 0));
    while (!q.empty()) {
        pair<string, int> t = q.front(); q.pop();
        if (mem.count(t.first) == 1) continue;
        if (t.second > 10) {
            cout << "NO ANSWER!" << endl;
            return ;
        }
        if (t.first == b) {
            cout << t.second << endl;
            return ;
        }
        mem[t.first] = 1;
        for (const auto& it: rule) {
            size_t idx = 0;
            idx = t.first.find(it.first);
            while (idx != string::npos) {
                string t1 = t.first;
                for (auto rule_t: it.second) {
                    t1.replace(idx, it.first.size(), rule_t);
                    q.push(make_pair(t1, t.second+1));
                }
                idx = t.first.find(it.first, idx+it.first.size());
            }
        }
    }
    cout << "NO ANSWER!" << endl;
}

int main() {
    cin >> a >> b;
    string k, v;
    while (cin >> k >> v) {
        rule[k].push_back(v);
    }
    bfs();
    return 0;
}
