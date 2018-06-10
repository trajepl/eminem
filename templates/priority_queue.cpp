#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct compare {
    bool operator()(const int &l, const int &r) {return l < r;}
};

int main() {
    priority_queue<int, vector<int>, compare> q;
    q.push(3);
    q.push(1);
    q.push(5);

    while(!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl; 
    return 0;
}
