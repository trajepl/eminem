// Longest Palindromic Subsequence
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// no delete operator
int longestPalindromeSeq(string s) {
    // handle the input
    string str(s.size()*2+1, '#');
    for (int i = 0; i < s.size(); ++i) {
        str[2*i+1] = s[i];
    }
    int id = 0, lenp = 1;
    int ret = 0;
    int len_str = str.size();
    vector<int> p(s.size()*2+1, 1);
    for (int i = 0; i < len_str; ++i) {
        p[i] = lenp > i ? min(p[2*id-i], lenp-i):1;
        while (i + p[i] < len_str && i - p[i] >= 0 &&
                str[i-p[i]] == str[i+p[i]]) {
            p[i]++;
        }
        if (i + p[i] > lenp) {
            lenp = i + p[i];
            id = i;
        }

        if (p[i] > ret) ret = p[i];
    }
    return ret-1;
}

int longestPalindromeSubseq(string s) {
    int len = s.size();
    vector<vector<int>> dp(len, vector<int>(len, 0));
    for (int i = 0; i < len; ++i) {
        dp[i][i] = 1;
    }

    for (int i = len-2; i >= 0; --i) {
        for (int j = i+1; j < len; ++j) {
            if (s[i] == s[j]) dp[i][j] = dp[i+1][j-1] + 2;
            else dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
        }
    }

    return dp[0][len-1];
}

int longestPalindromeSubseq_1(string s) {
    int n = s.size(), res = 0;
    vector<int> dp(n, 1);
    for (int i = n-1; i >= 0; --i) {
        int len = 0;
        for (int j = i+1; j < n; ++j) {
            int t = dp[j];
            if (s[i] == s[j]) dp[j] = len+2;
            else dp[j] = max(dp[j], dp[j-1]);
            len = t;
        }
    }
    return dp[n-1];
}

int main() {
    cout << longestPalindromeSubseq_1("cvvd") << endl;
    return 0;
}
