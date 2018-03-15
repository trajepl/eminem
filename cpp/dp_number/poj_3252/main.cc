#include <iostream>
#include <vector>

using namespace std;

vector<int> digit;
vector<vector<int>> dp;
int cur;

int dfs(int pos, int state, bool lead, bool limit) {
    if(pos == -1) {
        if(state >= 32) return 1;
        else return 0;
    }

    if(!limit && !lead && dp[pos][state] != -1) return dp[pos][state];

    int up = limit ? digit[pos] : 1;
    int sum = 0;
    for(int i = 0; i <= up; i++) {
        if(lead && i == 0) sum += dfs(pos - 1, state, lead, limit && i == digit[pos]);
        else {
            int tmp = state;
            if (i == 0) ++tmp;
            if (i == 1) --tmp;
            sum += dfs(pos - 1, tmp, false, limit && i == digit[pos]);
        }
    }
    if(!limit && !lead) dp[pos][state] = sum;
    return sum;
}

int solve(int x) {
    while (x) {
        digit.push_back(x & 1);
        x >>= 1;
    }

    int len = digit.size();
    int ret = dfs(len-1, 32, true, true);

    digit.clear();
    return ret;
}

int main() {
    int l, r;
    dp = vector<vector<int>>(32, vector<int>(66, -1));

    while(cin >> l && cin >> r)
        cout << solve(r) - solve(l-1) << endl;
    return 0;
}