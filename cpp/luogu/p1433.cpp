#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <iomanip>

using namespace std;

int n;
vector<vector<double>> dis;
vector<pair<double, double>> points;
vector<vector<double>> dp;

double eu_dis(double x1, double x2, double y1, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double helper(int status, int start) {
    if (dp[status][start] != INT32_MAX)
        return dp[status][start];
    if (status == (1 << (n + 1)) - 1) {
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        if (status >> i & 1) continue;
        dp[status][start] = min(helper(1 << i | status, i) + dis[start][i], dp[status][start]);
        
    }
    return dp[status][start];
}

int main() {
    cin >> n;
    points = vector<pair<double, double>>(n+1, make_pair(0, 0));
    dis = vector<vector<double>>(n+1, vector<double>(n+1, 0));
    dp = vector<vector<double>>((1 << (n + 1)), vector<double>(n+1, INT32_MAX));
    for (int i = 1; i <= n; ++i) {
        double a, b; cin >> a >> b;
        points[i] = make_pair(a, b);
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j <= n; ++j) {
            dis[i][j] = eu_dis(
                points[i].first,
                points[j].first,
                points[i].second,
                points[j].second
            );
            dis[j][i] = dis[i][j];
        }
    }
    cout << fixed <<  setprecision(2) << helper(1, 0) << endl;
    return 0;
}