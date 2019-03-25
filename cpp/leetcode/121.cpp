class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int profit = 0;
        int min_p = prices[0];
        int max_p = -1;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > min_p) profit = max(profit, prices[i]-min_p);
            min_p = min(min_p, prices[i]);
        }
        return profit;
    }
};
