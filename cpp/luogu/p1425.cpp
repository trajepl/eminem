#include <iostream>

using namespace std;

int main() {
    int s1, s2;
    int e1, e2;
    cin >> s1 >> s2 >> e1 >> e2;
    if (e2 >= s2) {
        cout << e1 - s1 << " " << e2 - s2 << endl;
    }
    else {
        cout << e1 - s1 - 1 << " " << e2 + 60 - s2 << endl;
    }
    return 0;
}
