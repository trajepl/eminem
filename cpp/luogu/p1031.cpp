#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> arr = vector<int>(n, 0);
    int total = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        total += arr[i];
    }

    int res = 0;
    int avg_arr = total / n;
    for (int i = 0; i < n-1; ++i) {
        int diff = arr[i] - avg_arr;
        if (arr[i] != avg_arr) {
            arr[i] -= diff;
            arr[i+1] += diff;
            res++;
        }
    }

    cout << res << endl;
    return 0;
}
