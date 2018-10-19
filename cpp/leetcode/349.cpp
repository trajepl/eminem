class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> cnt_map = map<int, int>();
        vector<int> ret = vector<int>();
        for (auto it: nums1) cnt_map.insert(make_pair(it, 1));
        for (auto it: nums2) {
            if (cnt_map.find(it) != cnt_map.end()) {
                if (cnt_map[it] != 1) continue;
                else ret.push_back(it);
                cnt_map[it]++;
            }
        }
        return ret;
    }
};
