// o2 优化过
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> grid(9, vector<int>(9, 0));
vector<vector<int>> points;
vector<vector<int>> std_scores(9, vector<int>(9, 0));
vector<int> row(9, 1);
vector<int> col(9, 1);
vector<int> squ(9, 1);
int rls = -1;

int ith_squ(int a, int b) {
    return a / 3 * 3 + b / 3;
}

int scores() {
    int total = 0;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            total += grid[i][j] * std_scores[i][j];
        }
    }
    return total;
}

void gen_squ(size_t n) {
    if (n >= points.size()) {
        rls = max(rls, scores());
        return ;
    }
    int i = points[n][0];
    int j = points[n][1];

    if (grid[i][j] > 0) {
        gen_squ(n + 1);
        return ;
    }
    if (grid[i][j] == 0) {
        bool flag = true;
        for (int k = 1; k <= 9; ++k) {
            if ((row[i] >> k) & 1 || (col[j] >> k) & 1 || (squ[ith_squ(i, j)] >> k) & 1 ) {
                continue;
            }
            flag = false;
            grid[i][j] = k;
            row[i] |= (1 << k);
            col[j] |= (1 << k);
            squ[ith_squ(i, j)] |= (1 << k);

            gen_squ(n + 1);

            grid[i][j] = 0;
            int mark = (~0) ^ (1 << k);
            row[i] &= mark;
            col[j] &= mark;
            squ[ith_squ(i, j)] &= mark;
        }
        if (flag) {
            return ;
        }   
    }
}

int main() {
    for (int i = 0; i < 9; ++i) {
        int zero_cnt = 0;
        for (int j = 0; j < 9; ++j) {
            cin >> grid[i][j];

            if (grid[i][j] == 0) {
                ++zero_cnt;
                points.push_back({i, j, 0});
            }

            row[i] |= 1 << grid[i][j];
            col[j] |= 1 << grid[i][j];
            squ[ith_squ(i, j)] |= 1 << grid[i][j];

            std_scores[i][j] = 5 + min(min(i+1, 9-i), min(j+1, 9-j));
        }
        int idx = points.size()-1;
        for (int j = 0; j < zero_cnt; ++j) {
            points[idx-j][2] = zero_cnt;
        }
    }
    sort(points.begin(), points.end(), 
        [](const auto& a, const auto& b) {
            if (a[2] == b[2]) {
                if (a[0] == b[0])
                    return a[1] < b[1];
                return a[0] < b[0];
            }
            return a[2] < b[2];
        }
    );
    if (points.size() == 0)
        rls = scores();
    else
        gen_squ(0);
    cout << rls << endl;
    return 0;
}