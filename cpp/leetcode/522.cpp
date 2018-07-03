#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;

struct cmp {
public:
    bool operator() (pair<string, int> p1, pair<string, int>p2) {
        if (p1.second > p2.second) return false;
        else return true;
    }
};

bool isLCS(string &s1, string &s2) {
    int len1 = s1.size(), len2 = s2.size();
    int i = 0, j = 0;
    while (i < len1 && j < len2) {
        if (s1[i] == s2[j]) {
            i++; j++;
        } else {
            j++;
        }
    }
    if (i == len1) return true;
    return false;
}

int findLUSlength(vector<string> &strs) {
    int len = strs.size();
    map<string, int> strs_cnt;

    priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
    for (string str: strs) {
        pq.push(make_pair(str, str.size()));
        if (strs_cnt.count(str) == 0) strs_cnt[str] = 1;
        else strs_cnt[str] = strs_cnt[str] + 1;
    }
    vector<string> model;
    while (!pq.empty()) {
        pair<string, int> t = pq.top(); pq.pop();
        if (model.empty() && strs_cnt[t.first] == 1) return t.second;
        else {
            if (model.empty()) {
                model.push_back(t.first);
            } else {
                bool flag = false;
                for (auto model_s: model) {
                    if (isLCS(t.first, model_s)) {
                        flag = true;
                        break;
                    }
                }
                if (!flag && strs_cnt[t.first] == 1) return t.second;
                else model.push_back(t.first);
            }
        }
   }
   return -1;
}

int main() {
    vector<string> strs = {{"ab", "abc", "abc"}};
    cout << findLUSlength(strs) << endl;
    return 0;
}
