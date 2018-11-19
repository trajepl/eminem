class Solution {
public:
    int countMerge(vector<long>& sums, int l, int r, int lower, int upper) {
        if (r-l <= 1) return 0;
        int mid = (l + r) / 2;
        int count = countMerge(sums, l, mid, lower, upper) +
                    countMerge(sums, mid, r, lower, upper);
        vector<long> cur = vector<long>(sums.begin()+l, sums.begin()+r);
        int l_sum = mid, r_sum = mid, t = mid;

        for (int i = l, j = 0; i < mid; ++i, ++j) {
            while (l_sum < r && sums[l_sum] - sums[i] < lower) l_sum++;
            while (r_sum < r && sums[r_sum] - sums[i] <= upper) r_sum++;
            while (t < r && sums[t] < sums[i]) cur[j++] = sums[t++];
            cur[j] = sums[i];
            count += r_sum - l_sum;
        }
        copy(cur.begin(), cur.end(), sums.begin() + l);
        return count;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int l = 0, r = nums.size();
        vector<long> sums = vector<long>(r+1, 0);
        for (int i = 0; i < r; ++i) {
            sums[i+1] = sums[i] + nums[i];
        }
        return countMerge(sums, l, r+1, lower, upper);
    }
};
