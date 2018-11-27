#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bagOfTokensScore(vector<int>& tokens, int P) {
    sort(tokens.begin(), tokens.end());
    int score = 0, ans = 0;
    int lo = 0, hi = tokens.size()-1;
    while (lo <= hi) {
        if (tokens[lo] <= P) {
            P -= tokens[lo++];
            score++;
            ans = max(ans, score);
        } else if (score > 0){
            P += tokens[hi--];
            score--;
        }
    }
    return ans;
}
