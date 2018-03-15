#include <iostream>
#include <vector>

using namespace std;

int backpack(vector<pair<int, int>> p, int total) {
    vector<int> dp(total+1, 0);
    for(int i = 0; i < p.size(); i++) {
        for(int j = total; j > 0; j--) {
            if(j >= p[i].first) 
                dp[j] = max(dp[j-p[i].first] + p[i].second, dp[j]);
        }
    }
    return dp[total];
}
    
int main() {
    int n, total;
    cin >> n >> total;
    vector<pair<int, int>> p;

    while(n-- > 0) {
        int w, v;
        cin >> w >> v;
        p.push_back(make_pair(w, v));
    }
    cout << backpack(p, total) << endl;
    return 0;
}
