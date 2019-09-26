#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> t;

long long int merge_sort(int l, int r) {
    if (l >= r-1) return 0;
    long long int rls = 0;
    int mid = (r + l) >> 1;
    rls += merge_sort(l, mid);
    rls += merge_sort(mid, r);

    int i = l, j = mid, k = l;

    while (i < mid && j < r) {
        if (arr[i] > arr[j]) {
            rls += mid - i;
            t[k++] = arr[j++];
        } else {
            t[k++] = arr[i++];
        }
    }
    while (i < mid) t[k++] = arr[i++];
    while (j < r) t[k++] = arr[j++];
    for (int i = l; i < r; ++i) {
        arr[i] = t[i];
    }
    return rls;
}

int main() {
    int n; cin >> n;
    arr = vector<int>(n, 0);
    t = vector<int>(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << merge_sort(0, n) << endl;
    return 0;
}