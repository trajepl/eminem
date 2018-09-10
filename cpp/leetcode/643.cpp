#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int> &vec, int k) {
        int sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += vec[i];
        }
        int new_sum = sum;
        for (int i = k; i < vec.size(); ++i) {
            new_sum = new_sum - vec[i-k] + vec[i];
            if (new_sum > sum) sum = new_sum;
        }
        return sum*1.0 / k;
    }
};

int main() {
    vector<int> vec = {1, 12, -5, -6, 50, 3};
    Solution sol = Solution();
    cout << sol.findMaxAverage(vec, 4) << endl;
    return 0;
}
