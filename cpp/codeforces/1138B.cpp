#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main () {
    int n; cin >> n;
    string c, a; cin >> c >> a;
    vector<int>s_00, s_10, s_01, s_11;
    for (int i = 0; i < n; ++i) {
        if (c[i] == '0' && a[i] == '0') s_00.push_back(i+1);
        else if (c[i] == '1' && a[i] == '0') s_10.push_back(i+1);
        else if (c[i] == '0' && a[i] == '1') s_01.push_back(i+1);
        else if (c[i] == '1' && a[i] == '1') s_11.push_back(i+1);
    }
    for (int i = 0; i <= s_10.size(); ++i) {
        for (int j = 0; j <= s_11.size(); ++j) {
            int s = s_01.size() - (i + j - (s_11.size() - j));
            if (s >= 0 && s <= s_01.size()) {
                int k = n / 2 - i - j - s;
                if (k >= 0 && k <= s_00.size()) {
                    for (int p = 0; p < k; ++p) cout << s_00[p] << " "; 
                    for (int p = 0; p < i; ++p) cout << s_10[p] << " "; 
                    for (int p = 0; p < s; ++p) cout << s_01[p] << " "; 
                    for (int p = 0; p < j; ++p) cout << s_11[p] << endl; 
                    return 0;
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
