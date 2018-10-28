#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    int maxL = 1, res = 0;
    vector<pair<int, int>> dp = vector<pair<int, int>>(n, make_pair(1, 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                if (dp[i].first == dp[j].first + 1) dp[i].second += dp[j].second;
                if (dp[i].first < dp[j].first + 1) {
                    dp[i].first = dp[j].first + 1;
                    dp[i].second = dp[j].second;
                }
            }
        }
        if (maxL == dp[i].first) {
            res += dp[i].second;
        }
        if (maxL < dp[i].first) {
            maxL = dp[i].first;
            res = dp[i].second;
        }
    }
    return res;
}

int main() {
    vector<int> nums = {1,3,5,4,7};
    cout << findNumberOfLIS(nums) << endl;
    return 0;
}
