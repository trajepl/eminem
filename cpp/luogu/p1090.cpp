#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n; cin >> n;
    priority_queue<int, vector<int>, greater<int>> nums;
    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        nums.push(t);
    }
    int res = 0;
    while (nums.size() > 1) {
        int a = nums.top(); nums.pop();
        int b = nums.top(); nums.pop();
        int sum_t = a + b;
        res += sum_t;
        nums.push(sum_t);
    }
    cout << res << endl;
    return 0;
}
