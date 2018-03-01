#include <iostream>
#include <string>
#include <vector>

using namespace std;

int max_len_pld(string s) {
    int ret = 0;

    // handle the string
    string s_handle(s.size()*2 + 1, '#');
    for(int i = 0; i < s.size(); i++) {
        s_handle[2*i+1] = s[i];
    }
    cout << s_handle << endl;
    // cal max palindrome length
    vector<int> p(s_handle.size());
    p[0] = 0;
    int id = 0, lenp = 1;
    for(int i = 1; i < s_handle.size(); i++) {
        /*
         * if(len-i > p[2*id - 1]) p[i] = p[2*id-1];
         * else p[i] = lenp - i;
         * */
        p[i] = (lenp > i) ? min(p[2*id - i], lenp-i) : 1;
        while(i+p[i] < s_handle.size() && i - p[i] >= 0 && s_handle[i+p[i]] == s_handle[i-p[i]]) p[i]++;
        if(i + p[i] > lenp) {
            lenp = i + p[i];
            id = i;
        }
        if(ret < p[i]) ret = p[i];
    }
    return ret-1;
}

int main() {
    int cnt;
    cin >> cnt;
    string s;
    while(cnt-- > 0) {
        cin >> s;
        cout << max_len_pld(s) << endl;
    }
    return 0;
}
