#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int run(string s) {
    string t;
    int ret = s.size();
    for (int i = 0; i < s.size(); i++) {
        if (i < s.size() && s[i] == s[i+1])
            while (s[i] == s[i+1]) i++;
        else {
            t.append(1, s[i]);
            ret--;
        }
    }

    int len = t.size();
    if(len == 0) return ret+1;
    if(len == 1 || len == 2) return ret+2;
    
    int add = 0;
    for (int i = 0; i < len-2; i++) {
        int m = 0;
        if (t[i] == t[i+2]) {
            m += 4;
            int r = 2 * (i+1);
            for(int j = i-1; j >= 0 && r-j < len; j--) {
                if (t[j] == t[r-j]) m += 2;
            }
            add = max(-1, m);
        }
    }
    return (add == 0) ? ret + 2 : ret + add;
}

int main() {
    int n; cin >> n;

    while(n-- > 0) {
        string s; cin >> s;
        cout << run(s) << endl;
    }

    return 0;
}
