#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> arr;
    int h;
    while (cin >> h) {
        arr.push_back(h);
    }

    int n = arr.size();
    vector<int> helper = vector<int>(n, 0);
    vector<int> num = vector<int>(n, 0);
    helper[0] = arr[0];
    num[0] = arr[0];

    int rls1 = 1, rls2 = 1;
    for (int i = 1; i < n; ++i) {
        if (arr[i] <= helper[rls1-1])
            helper[rls1++] = arr[i];
        auto idx = upper_bound(helper.begin(), helper.begin() + rls1, arr[i], greater<int>());
        *idx = arr[i];
        if (arr[i] > num[rls2-1])
            num[rls2++] = arr[i];
        idx = lower_bound(num.begin(), num.begin() + rls2, arr[i]);
        *idx = arr[i];
    
    }
    cout << rls1 << endl << rls2 << endl; 
    return 0;
}