#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findShortestSubarray(vector<int> &arr) {
        unordered_map<int, pair<int, int> > unmap;
        unordered_map<int, int> dup;
        for (int i = 0; i < arr.size(); ++i) {
            if (unmap.find(arr[i]) == unmap.end()) {
                pair<int, int> p = make_pair(i, i);
                unmap.insert(make_pair(arr[i], p));
                dup.insert(make_pair(arr[i], 1));
            } else {
                unmap[arr[i]].second = i;
                dup[arr[i]]++;
            }
        }
        
        int min = arr.size();
        int max = 0;
        for (unordered_map<int, pair<int, int> >::iterator 
                it = unmap.begin(); it != unmap.end(); ++it) {
            int dis = it->second.second - it->second.first;
            if (dup[it->first] > max) {
                min = dis;
            } else if(dup[it->first] == max) {
                min = (min > dis) ? dis : min;
            }
        }
        return min + 1;
    }
};

int main() {
    int a[] = {1, 2, 3, 3, 2};
    int n = sizeof(a) / sizeof(int);
    vector<int> arr = vector<int>(a, a+n);

    Solution sol = Solution();
    cout << sol.findShortestSubarray(arr) << endl;
    return 0;
}
