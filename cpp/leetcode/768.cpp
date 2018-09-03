#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int max = arr[0];
        int ret = 1;
        
        for (int i = 1; i < arr.size(); ++i) {
            int min = arr[i];
            for (auto it = arr.cbegin()+i; it != arr.cend(); ++it) {
                if (*it < min) min = *it;
            }
            if (max > min) {
                max = (arr[i] > max)? arr[i] : max;
            } else {
                ret++;
                max = arr[i];
            }
        }
        return ret;
    }
};

int main() {
    vector<int> arr = {2,1,3,3,4};
    Solution sol = Solution();
    int ret = sol.maxChunksToSorted(arr);
    cout << ret << endl;
    return 0;
}
