#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> cal_next(string p) {
    int len = p.size();
    vector<int> next(len+1);
    next[0] = -1;
    int k = -1;
    int j = 0;

    while(j < len) {
        if(k == -1 || p[k] == p[j]) {
            ++k; ++j;
            next[j] = k;
        } else {
            k = next[k];
        }
    }

    return next;
}

int kmp(string s, string p) {
    int cnt= 0;
    int k = 0, i = 0;
    int len = p.size();
    vector<int> next = cal_next(p);
    
    while(i < s.size()) {
        if(k == -1 || p[k] == s[i]) {
            if(k == len-1) {
                cnt++;
                k = next[k];
            } else {
                ++k; ++i;
            }
        } else {
            k = next[k];
        }
    }
    return cnt;
}

int main() {
    int cnt;
    cin >> cnt;
    string s, p;
    while(cnt-- > 0) {
        cin >> p;
        cin >> s;
        cout << kmp(s, p) << endl;
    }
    return 0;
}
