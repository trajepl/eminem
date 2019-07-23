class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        vector<long> prefix_sum = vector<long>(len+1, 0);
        for (int i = 0; i < len; ++i) {
            prefix_sum[i+1] = prefix_sum[i] + nums[i];
        }
        int ret = 0;
        for (int i = 0; i < len; ++i) {
            for (int j = i+1; j <= len; ++j) {
                int sum_ij = prefix_sum[j] - prefix_sum[i];
                if (sum_ij == k) ret++;
            }
        }
        return ret;
    }
};
