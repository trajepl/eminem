#include <iostream>
#include <vector>

#define MAX_NUM 40000*2

using namespace std;

int minIncrementForUnique(vector<int>& A) {
    int cnt = 0;
    int duplicate_cnt = 0;
    vector<int> vec_map = vector<int>(MAX_NUM, 0);
    for (int i: A) {
        if (vec_map[i] > 0) duplicate_cnt++;
        vec_map[i]++; 
    }
    for (int i: A) {
        if (vec_map[i] <= 1) continue;
        while (vec_map[i] > 1) {
            int i_t = i;
            while (vec_map[++i_t] != 0);
            vec_map[i_t] = 1;
            vec_map[i]--;
            cnt += i_t - i;
        }
    }
    return cnt;
}

int main() {
    vector<int> A = {1,2,2};
    cout << minIncrementForUnique(A) << endl;
    return 0;
}
