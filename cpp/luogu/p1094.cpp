#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int b_search(vector<int>& arr, int n, int l, int r, int max_w) {
    while (l < r) {
        int mid = (l + r) / 2;
        if (n + arr[mid] > max_w) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l-1;
}

int main() {
    int max_w, n; cin >> max_w >> n;
    vector<int> gifts = vector<int>(n, 0);
    vector<int> visited = vector<int>(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> gifts[i]; 
    }
    int res = 0;
    sort(gifts.begin(), gifts.end());
    for (int i = 0; i < n; ++i) {
        if (visited[i]) continue;
        visited[i] = 1;
        int idx = b_search(gifts, gifts[i], i+1, n, max_w);
        while (visited[idx]) {
            idx--;
        }
        if (idx > i) {
            visited[idx] = 1;
        }
        res++;
    }
    cout << res << endl;

    return 0; 
}
