#include <iostream>
#include <vector>

using namespace std;

void swap(char &a, char &b) {
    char c = a;
    a = b; b = c;
}

void rotate(vector<vector<char>> &pos) {
    for (int i = 0; i < 3; ++i) {
        for (int j = i; j < 3; ++j) {
            swap(pos[i][j], pos[j][i]);
        }
    }
    for (int i = 0; i < 1; ++i) {
        for (int j = 0; j < 3; ++j) {
            swap(pos[j][i], pos[j][3-1-i]);
        }
    }
}

void find(vector<vector<char>> map, vector<vector<char>> pos) {
    int n = map.size(), m = map[0].size();
    for (int i = 1; i < n - 1; ++i) {
        for (int j = 1; j < m - 1; ++j) {
            if (map[i][j] == pos[1][1]) {
                for (int k = 0; k < 4; ++k) {
                    bool same = true;
                    for (int it = i - 1; it <= i + 1; ++it) {
                        for (int jt = j - 1; jt <= j + 1; ++jt) {
                            if (map[it][jt] != pos[it-i+1][jt-j+1]) {
                                same = false;
                                break;
                            }
                        }
                        if (!same) break;
                    }
                    if (same) {
                        cout << i+1 << " " << j+1 << endl;
                        break;
                    }
                    rotate(pos);
                }
            }
        }
    }
}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<char>> map(n, vector<char>(m, ' '));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
        }
    }
    vector<vector<char>> pos(3, vector<char>(3, ' '));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> pos[i][j];
        }
    }
    find(map, pos);
    return 0;
}
