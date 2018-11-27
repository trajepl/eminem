#include <iostream>
#include <vector>

using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int len_push = pushed.size();
    int len_pop = popped.size();
    vector<bool> visited = vector<bool>(len_push, false);
    int i = 0, j = 0;
    while (j < len_push) {
        if (visited[j]) {
            ++j; continue;
        }
        if (!visited[j] && pushed[j] != popped[i]) {
            ++j; continue;
        }
        while (j < len_push && i < len_pop && !visited[j] && pushed[j] == popped[i]) {
            visited[j] = true;
            while (j > 0 && visited[--j]);
            i++;
        }
    }
    for (bool v: visited) {
        if (!v) return false;
    }
    return true;
}

int main() {
    vector<int> pushed = {1,2,3,4,5};
    vector<int> popped = {4,3,5,1,2};
    cout << validateStackSequences(pushed, popped) << endl;
    return 0;
}
