#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> digit_r;
vector<vector<int>> dp;

int f(int x) {
    if(x == 0) return 0;  
    int ans = f(x/10);  
    return ans*2+(x%10);  
}

int dfs(int pos, int state, bool limit) {
    int ret = 0;
    if(pos == -1) {
        if(state >= 0) return 1;
    }
    if(state < 0) return 0;
    
    if(!limit && dp[pos][state] != -1) return dp[pos][state];

    int up = limit ? digit_r[pos] : 9;
    for (int i = 0; i <= up; i++) {
        int bias = i * (1 << pos);
        ret += dfs(pos - 1, state - bias, limit && i == digit_r[pos]);
    }
    
    if(!limit) dp[pos][state] = ret;
    return ret;
}

int solve(int l, int r) {
    while (r) {
        digit_r.push_back(r % 10);
        r /= 10;
    }

    int k = f(l);
    int ret = dfs(digit_r.size() - 1, k, true);
    digit_r.clear();

    return ret;
}

int main() {
    int n;
    int l, r;
    int idx = 0;

    dp = vector<vector<int>>(10, vector<int>(5200, -1));

    cin >> n;
    while (n-- > 0) {
        cin >> l >> r;
        cout << "Case #" << ++idx << ": " << solve(l, r) << endl;
    }
    return 0;
}
