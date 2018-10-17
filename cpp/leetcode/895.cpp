#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;

class FreqStack {
private:
    map<int, stack<int>> fstack;
    map<int, int> cnt_map;
    int max_cnt;
public:
    FreqStack() {
        max_cnt = 0;
        cnt_map = map<int, int>();
        fstack = map<int, stack<int>>(); 
    }

    void push(int x) {
        map<int, int>::iterator it = cnt_map.find(x);
        if (it == cnt_map.end()) {
            cnt_map[x] = 1;
            fstack[1].push(x);
        } else {
            cnt_map[x]++;
            fstack[cnt_map[x]].push(x);
        }
        if (cnt_map[x] > max_cnt) max_cnt = cnt_map[x];
    }

    int pop() {
        int ret = fstack[max_cnt].top();
        fstack[max_cnt].pop();
        if (fstack[max_cnt].empty()) max_cnt--;
        cnt_map[ret]--;
        return ret;
    }
};

int main() {
    FreqStack obj = FreqStack();
    obj.push(1);
    int param_2 = obj.pop();
    return 0;
}
