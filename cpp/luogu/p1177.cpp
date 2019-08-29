#include <iostream>
#include <vector>
#include <random>

using namespace std;
int nums[1000001];

void quick_sort(int l, int r) {
    if (l >= r) return ;
    default_random_engine e;
    uniform_int_distribution<int> u(l, r-1); 
    int t = u(e);
    int f = nums[t];
    swap(nums[t], nums[l]);
    int small = l;
    for (int i = l+1; i < r; ++i) {
        if (nums[i] < f) {
            ++small;
            if (i != small) {
                swap(nums[i], nums[small]);
            }
        }
    }
    swap(nums[small], nums[l]);
    quick_sort(l, small);
    quick_sort(small+1, r);
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    quick_sort(0, n);
    for (int i = 0; i < n; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
