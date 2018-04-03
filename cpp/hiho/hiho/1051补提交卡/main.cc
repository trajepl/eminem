#include <iostream>
#include <vector>

using namespace std;

int run(int m, vector<int> date) {
    int len = date.size();
    int ret = 0;
    for(int i = 0; i < len-m-1; i++) {
        int mul = date[i+m+1] - date[i];
        ret = (ret > mul) ? ret : mul ;
    } 
    return ret-1;
}

int main() {
    int cnt; cin >> cnt;
    while (cnt--) {
        int n; cin >> n;
        int m; cin >> m;
        
        vector<int> date(n+2, 0);
        for(int i = 1; i <= n; i++) {
           cin >> date[i]; 
        }
        date[n+1] = 101;

        if (n <= m) {
            cout << 100 << endl;
            continue;
        }

        cout << run(m, date) << endl;
    }
    return 0;
}
