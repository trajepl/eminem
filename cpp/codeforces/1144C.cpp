#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {
    int n; cin >> n;
    unordered_map<int, int> m = unordered_map<int, int>();
    priority_queue<int, vector<int>, greater<int>> q_inc;
    priority_queue<int, vector<int>, less<int>> q_des;
    while (n--) {
        int i; cin >> i;
        if (m.find(i) == m.end())  {
            q_des.push(i);
            m.insert(make_pair(i, 1));
        } else {
            m[i] += 1;
            if (m[i] >= 3) {
                cout << "NO" << endl;
                return 0;
            }
            q_inc.push(i);
        }
    }
    cout << "YES" << endl;      
    cout << q_inc.size() << endl;
    if (q_inc.size() == 0) {
        cout << endl;
    } else { 
        while (q_inc.size() > 1) {
            cout << q_inc.top() << " ";
            q_inc.pop();
        }
        cout << q_inc.top() << endl;
    }

    cout << q_des.size() << endl;
    if (q_des.size() == 0) {
        cout << endl;
    } else {
        while (q_des.size() > 1) {
            cout << q_des.top() << " ";
            q_des.pop();
        }
        cout << q_des.top() << endl;
    }

    return 0;
}
