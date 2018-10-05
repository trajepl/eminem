#include <iostream>
#include <vector>
#include <string>

using namespace std;

string shiftingLetters(string S, vector<int>& shifts) {
    char a[S.length()];
    strcpy(a, S.c_str());

    int len = shifts.size();
    
    for (int i = 0; i < len; ++i) shifts[i] %= 26;
   
    vector<int> sum_shifts(len, 0);
    for (int i = 0; i < len; ++i) {
        if (i == 0) sum_shifts[i] = shifts[i];
        else sum_shifts[i] = sum_shifts[i-1] + shifts[i];
    }

    int sum_step = sum_shifts.back();
    shifts[0] = sum_step % 26;
    for (int i = 1; i < len; ++i) {
        shifts[i] = sum_step - sum_shifts[i-1];
        shifts[i] %= 26;
    }
    // cout << shifts[2] << endl;
    for (int i = 0; i < len; ++i) {
        if (a[i] + shifts[i] > 'z') {
            a[i] = a[i] + shifts[i] - 'z' + 'a' - 1;
        } else {
            a[i] = a[i] + shifts[i];
        }
    }
    return a;
}

int main() {
    string s = "abc";
    vector<int> shifts = {3, 5, 9};
    cout << shiftingLetters(s, shifts) << endl;
    return 0;
}
