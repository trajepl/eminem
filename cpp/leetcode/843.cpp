#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

class Master {
    string secret = "hbaczn";
    public:
        int guess(string word) {
            int cnt = 0;
            for (auto p = word.begin(); p != word.end(); ++p) {
                if (*p == *(secret.begin() + (p - word.begin()))) {
                    cnt++;
                }
            }
            return cnt == 0 ? -1 : cnt;
        }
};

int comm_char_cnt(string &s1, string &s2) {
    int cnt = 0;
    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] == s2[i]) cnt++;
    }
    return cnt;
}

int findSecretWord(vector<string> &wordlist, Master &master) {
    int len = wordlist.size();

    vector<vector<int>> comm_cnt(len, vector<int>(len, len));
    for (int i = 0; i < len-1; ++i) {
        for (int j = i+1; j < len; ++j) {
            comm_cnt[i][j] = comm_char_cnt(wordlist[i], wordlist[j]);
            comm_cnt[j][i] = comm_cnt[i][j];
        }
    }

    srand((unsigned)time(NULL));
    int id = rand() % len;
    cout << id << endl;
    int cnt = 0;
    int cmp_cnt = 0;
    vector<bool> flag(len, true);

    while (cnt < 10) {
        cmp_cnt = master.guess(wordlist[id]);
        if (cmp_cnt == comm_cnt[id][id]) return 1;
        int true_len = len;
        for (int i = 0; i < len; ++i) {
            if (!flag[i]) {
                true_len--;
                continue;
            }
            if (cmp_cnt != comm_cnt[id][i]) {
                flag[i] = false;
            }
        }
        cout << true_len << endl;
        if (true_len == 0) return 1;
        int tmp_cnt = rand() % true_len;
        for (int i = 0; i < len; ++i) {
            if (flag[i]) {
                cout << "cat" << endl;
                tmp_cnt--;
                if (tmp_cnt == 0) {
                    id = i;
                    break;
                }
            }
        }
        cnt++;
    }
    return 0;
}

int main() {
    vector<string> wordlist = {"gaxckt","trlccr","jxwhkz","ycbfps","peayuf","yiejjw",
        "ldzccp","nqsjoa","qrjasy","pcldos","acrtag","buyeia","ubmtpj","drtclz",
        "zqderp","snywek","caoztp","ibpghw","evtkhl","bhpfla","ymqhxk","qkvipb",
        "tvmued","rvbass","axeasm","qolsjg","roswcb","vdjgxx","bugbyv","zipjpc",
        "tamszl","osdifo","dvxlxm","iwmyfb","wmnwhe","hslnop","nkrfwn","puvgve",
        "rqsqpq","jwoswl","tittgf","evqsqe","aishiv","pmwovj","sorbte","hbaczn",
        "coifed","hrctvp","vkytbw","dizcxz","arabol","uywurk","ppywdo","resfls",
        "tmoliy","etriev","oanvlx","wcsnzy","loufkw","onnwcy","novblw","mtxgwe",
        "rgrdbt","ckolob","kxnflb","phonmg","egcdab","cykndr","lkzobv","ifwmwp",
        "jqmbib","mypnvf","lnrgnj","clijwa","kiioqr","syzebr","rqsmhg","sczjmz",
        "hsdjfp","mjcgvm","ajotcx","olgnfv","mjyjxj","wzgbmg","lpcnbj","yjjlwn",
        "blrogv","bdplzs","oxblph","twejel","rupapy","euwrrz","apiqzu","ydcroj",
        "ldvzgq","zailgu","xgqpsr","wxdyho","alrplq","brklfk"};
    Master master;
    int ret = findSecretWord(wordlist, master);
    if(ret == 1) cout << "find" << endl;
    else cout << "not find" << endl;
    return 0;
}
