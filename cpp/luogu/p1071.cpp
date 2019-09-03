#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int visited[256] = {0};
int a_mem[256] = {0};
int b_mem[256] = {0};
unordered_map<char, char> cmap;

int main() {
    string a; cin >> a;
    string b; cin >> b;
    string q; cin >> q;
    
    int len = a.size();
    for (int i = 0; i < len; ++i) {
        a_mem[a[i]] = 1;
        b_mem[b[i]] = 1;
        if (cmap.find(a[i]) == cmap.end()) {
            if (!visited[b[i]]) {
                cmap[a[i]] = b[i];
                visited[b[i]] = 1;
            } else {
                cout << "Failed" << endl;
                return 0;
            }
        } else {
            if (cmap[a[i]] != b[i]) {
                cout << "Failed" << endl;
                return 0;
            }
        }
    }
    for (int i = 0; i < 26; ++i) {
        if (cmap.find('A'+i) == cmap.end()) {
            cout << "Failed" << endl;
            return 0;
        }
    }

    for (const auto it: a) {
        if (b_mem[it] == 0) {
            cout << "Failed" << endl;
            return 0;
        }
    }

    for (int i = 0; i < q.size(); ++i) {
        if (cmap.find(q[i]) == cmap.end()) {
            cout << "Failed" << endl;
            return 0;
        }
    }
    for (const char c: q) {
        cout << cmap[c];
    }
    cout << endl;
    return 0;
}
