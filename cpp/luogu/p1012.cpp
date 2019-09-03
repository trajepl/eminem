#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(string& a, string& b) {
    return a+b > b+a;
}

int main() {
    int n; cin >> n;
    vector<string> arr(n, "");
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), cmp);
    for (const string& s: arr) {
        cout << s;
    }
    cout << endl;
    return 0;
}
