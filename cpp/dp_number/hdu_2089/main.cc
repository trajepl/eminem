#include <iostream>
#include <vector>
using namespace std;

vector<int> char_num;
vector<vector<int>> dp; // i: idx of char_num  j: the state of whether pre position is 6

int dfs(int pos, int pre, int state, bool limit) {
    if(pos == -1) return 1;
    if(!limit && dp[pos][state] != -1) return dp[pos][state];

    int up = limit ? char_num[pos] : 9;
    int cnt = 0;
    for(int i = 0; i <= up; ++i) {
        if(pre == 6 && i == 2) continue;
        if(i == 4) continue;
        
        cnt += dfs(pos-1, i, i == 6, limit && i == char_num[pos]);
    }
    
    if(!limit) dp[pos][state] = cnt;
    return cnt;
}

int solve(int x) {
    while (x) {
        char_num.push_back(x % 10);
        x = x / 10;
    }

    int len = char_num.size();
    dp = vector<vector<int>>(len, vector<int>(2, -1));

    int ret =  dfs(len-1, -1, 0, true);
    char_num.clear();
    return ret;
}

int main() {
    int l, r;
    while (true) {
        cin >> l; cin >> r;
        if(l == 0 && r == 0) break;
        cout << solve(r) - solve(l-1) << endl;
    }
    return 0;
}
