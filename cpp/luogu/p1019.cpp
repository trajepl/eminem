#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

int max_len = 0;
unordered_map<string, vector<string>> is_connected;
unordered_map<string, int> connect_len;
unordered_map<string, int> str_usage;
vector<string> words = vector<string>(41, "");

void dfs(string word, int len) {
    for (auto& it: is_connected[word]) {
        if (str_usage[it] > 0) {
            str_usage[it]--;
            dfs(it, len + it.size() - connect_len[word+it]);
            str_usage[it]++;
        } 
    }
    max_len = max(max_len, len);
}

int min_lastfix(string s1, string s2) {
    int len1 = s1.length();
    for (int i = 0; i < s2.length()-1; ++i) {
        if (s1[len1-1] == s2[i]) {
            int p1 = len1 - 2;
            int p2 = i - 1;
            while (p1 > 0 && p2 >= 0 && s1[p1] == s2[p2]) {
                p1--;
                p2--;
            }            
            if (p2 < 0) {
                return i+1;
            }
        }
    }
    return 0;
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
        str_usage[words[i]] = 2;
    }
    string start; cin >> start;
    words[n] = "t" + start;

    for (int i = 0; i <= n; ++i) {
        if (words[i].length() == 1) continue;
        for (int j = 0; j < n; ++j) {
            int commen_len = min_lastfix(words[i], words[j]);
            if (commen_len) {
                is_connected[words[i]].push_back(words[j]);
                connect_len[words[i]+words[j]] = commen_len;
            }
        }
    }
    dfs(words[n], 1);
    cout << max_len << endl;
    return 0;
}
