#include <iostream>
#include <vector>

using namespace std;

string a, b, ab;
vector<int> mem = vector<int>(27, -1);
vector<int> visited = vector<int>(27, 0);
int n;
bool flag_total = true;

void dfs(int idx, char c, int carry) {
    /*
     * idx: i_th in the string
     * c: 第一个加数 或 第二个加数 或 和的i_th位置对应的字符串
     * carry: 进位
     */
    if (!flag_total) return ;
    if (idx < 0 && carry == 0) {
        for (int i = 0 ; i < n; ++i) {
            cout << mem[i] << " ";
        }
        flag_total = false;
        cout << endl;
        return ;
    }
    if (c == '-') return ;

    if (mem[c-'A'] == -1) {
        for (int i = n-1; i >= 0; --i) {
            if (visited[i]) continue;
            mem[c-'A'] = i;
            visited[i] = 1;
            
            if (mem[b[idx]-'A'] == -1) dfs(idx, b[idx], carry);
            else {
                int add_sum = mem[a[idx]-'A'] + mem[b[idx]-'A'] + carry;
                if (mem[ab[idx]-'A'] == -1) {
                    if (!visited[add_sum % n]) {
                        mem[ab[idx]-'A'] = add_sum % n;
                        if (idx > 0) dfs(idx-1, a[idx-1], add_sum / n);
                        else dfs(idx-1, '-', add_sum / n);
                        mem[ab[idx]-'A'] = -1;
                    }
                } else {
                    if (add_sum % n == mem[ab[idx]-'A']) {
                        if (idx > 0) dfs(idx-1, a[idx-1], add_sum / n);
                        else dfs(idx-1, '-', add_sum / n);
                    }
                } 
            } 

            visited[i] = 0;
            mem[c-'A'] = -1;
        }
    } else {
        if (mem[b[idx]-'A'] == -1) dfs(idx, b[idx], carry);
        else {
            int add_sum = mem[a[idx]-'A'] + mem[b[idx]-'A'] + carry;
            if (mem[ab[idx]-'A'] == -1) {
                if (!visited[add_sum % n]) {
                    mem[ab[idx]-'A'] = add_sum % n;
                    if (idx > 0) dfs(idx-1, a[idx-1], add_sum / n);
                    else dfs(idx-1, '-', add_sum / n);
                    mem[ab[idx]-'A'] = -1;
                }
            } else {
                if (add_sum % n == mem[ab[idx]-'A']) {
                    if (idx > 0) dfs(idx-1, a[idx-1], add_sum / n);
                    else dfs(idx-1, '-', add_sum / n);
                }
            } 
        } 
    }
}

int main() {
    cin >> n >> a >> b >> ab;
    dfs(n-1, a[n-1], 0);
    return 0;
}
