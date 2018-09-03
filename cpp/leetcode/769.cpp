#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int max = arr[0], min = arr[0];
        int left = 0, right = 0;
        int ret = 1;

        for (int i = 0; i < n-1; ++i) {
            cout << "[" << left << ", " << right << "]" << "    ";
            cout << "[" << min << ", " << max << "]" << endl;
            if (max == right && min == left) {
                ret++;
                left = i+1; right = i+1;
                min = arr[i+1]; max = arr[i+1];
                continue;
            }
            if (arr[i+1] > max) max = arr[i+1];
            if (arr[i+1] < min) min = arr[i+1];
            right++;
        }
        return ret;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> arr = {1, 0, 4, 2, 3};
    int ret = sol.maxChunksToSorted(arr);
    cout << ret << endl;
    return 0;
}
