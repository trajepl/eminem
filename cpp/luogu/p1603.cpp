#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cctype>

using namespace std;

unordered_map<string, int> mem;

vector<string> split(const string& s, const char& flag = ' ') {
    vector<string> res;
    istringstream iss(s);
    string t;
    while (getline(iss, t, flag)) {
        res.push_back(t);
    }
    return res;
}

int main() {
    mem["a"] = 1;
    mem["both"] = 2;
    mem["another"] = 1;
    mem["first"] = 1;
    mem["second"] = 2;
    mem["third"] = 3;
    string std_str = 
        "one two three four five six seven eight nine ten eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen twenty";
    vector<string> std_split_str = split(std_str);
    for (int i = 0; i < std_split_str.size(); ++i) {
        mem[std_split_str[i]] = i+1;
    }

    string s; 
    getline(cin, s);
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    vector<string> s_split = split(s);
    vector<int> nums;
    for (const auto it: s_split) {
        if (mem.find(it) != mem.end()) {
            int t = (mem[it] * mem[it]) % 100;
            nums.push_back(t);
        }
    }


    sort(nums.begin(), nums.end());
    string res = "";
    bool first_flag = true;
    for (const auto it: nums) {
        if (it < 10) {
            if (first_flag) {
                if (it != 0)
                    res += to_string(it); 
                first_flag = false;
            } else {
                res += "0" + to_string(it);
            }
        } else {
            res += to_string(it);
        } 
    }
    if (res.size() == 0) cout << 0 << endl;
    cout << res << endl;
    return 0;
}
