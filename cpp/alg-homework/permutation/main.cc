#include <iostream>
#include <vector>

using namespace std;

void per(vector<vector<int>> &ret, vector<int> &t, vector<bool> &visited, int len, int n) {
    if(t.size() == len) {
        ret.push_back(t);
        return ;
    }

    for(int i = 0; i < n; i++) {
        if(visited[i]) continue;
        visited[i] = true;
        t.push_back(i);
        per(ret, t, visited, len, n);
        t.pop_back();
        visited[i] = false;
    }
}

void test(int n, int len) {

    vector<vector<int>> ret;
    vector<int> t;
    vector<bool> visited(n, false);

    per(ret, t, visited, len, n);
    
    cout << "permutation(" << n <<  ", " << len << "): "<< endl;
    for(int i = 0; i < ret.size(); i++) {
        cout << i + 1 << ": ";
        for(int j = 0; j < ret[i].size(); j++)
            cout << ret[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int n = 6, len = 1;
    test(n, len);

    n = 6; len = 2;
    test(n, len);

    n = 3, len = 3;
    test(n, len);
    return 0;
}
