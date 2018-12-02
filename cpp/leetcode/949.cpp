#include <iostream>
#include <vector>
#include <string>

using namespace std;

void helper (vector<int> minitus, vector<int>& A, vector<bool>& visited, string& ans, string t_ans, int t_sec, int max_sec, int sum_sec) {
    if (ans.size() == A.size()) {
        if (sum_sec < max_sec) {
            if (t_sec < sum_sec) {
                t_sec = sum_sec;
                ans = t_ans;
            }
        }
        return ;
    }
    for (int i = 0; i < A.size(); ++i) {
        if (visited[i]) continue;
        visited[i] = true;
        helper(minitus, A, visited, ans, t_ans+to_string(A[i]), t_sec, max_sec, sum_sec+minitus[i]*A[i]);
        visited[i] = false;
    }
}

string largestTimeFromDigits(vector<int>& A) {
    int max_sec = 24 * 60;
    string ans = "";
    vector<int> minitus = {600, 60, 10, 1};
    vector<bool> visited = vector<bool>(A.size(), false);
    helper(minitus, A, visited, ans, "", 0, max_sec, 0);
    return ans.substr(0, 2) + ":" + ans.substr(2, 2);
}
