#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

int main() {
    int m, n;
    int t;
    int size_set = 0;
    cin >> m >> n;
    int res = 0;
    queue<int> q = queue<int>();
    vector<int> s = vector<int>(1000, 0);
    while (n--) {
        cin >> t;
        if (!s[t]) {
            if (size_set >= m) {
                int front = q.front();
                q.pop(); 
                s[front] = 0;
                size_set--;
            }
            size_set++;
            res++;
            q.push(t);
            s[t] = 1;
        }
    }
    cout << res << endl;
    return 0;
}
