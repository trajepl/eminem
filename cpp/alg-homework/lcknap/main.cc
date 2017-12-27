#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int lcknap(int m, vector<int> &p, vector<int> &w) {
    queue<vector<int>> q;
    q.push({-1, 0, 0});
    int maxcost = 0;
    int n = p.size();

    while(!q.empty()) {
        vector<int> t = q.front();
        q.pop();
        int i = t[0] + 1;

        if(t[1] > m) continue;
        if(t[0] == n-1) {
            if(maxcost < t[2]) 
                maxcost = t[2];
            continue;
        }

        q.push({i, t[1] + w[i], t[2] + p[i]});
        q.push({i, t[1], t[2]});
    }
    return maxcost;
}

void test(int m, vector<int> &p, vector<int> &w) {
    cout << "orginal dataset: " << endl;
    cout << "m = " << m << " : ";
    for(int i = 0; i < p.size(); i++)
        cout << "{" << p[i] << "," << w[i] << "} ";
    cout << endl;
    cout << "max value: " << lcknap(m ,p, w) << endl;
    cout << "----------" << endl;
}


int main() {
    int m;
    vector<int> p, w;

    m = 6;
    p = {1, 2, 5}, w = {2, 3, 4};
    test(m, p, w);

    cout << endl;

    m = 10;
    p = {4, 6, 7}, w = {3, 4, 5};
    test(m, p, w);

    cout << endl;

    m = 30;
    p = {2, 5, 8, 1}, w = {10, 15, 6, 9};
    test(m, p, w);
    return 0;
}
