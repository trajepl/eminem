#include <iostream>
#include <vector>

using namespace std;

#define MAXVAL ((unsigned)(-1)>>1)

vector<vector<int>> obst(int n, vector<double> &p, vector<double> &q) {
    vector<vector<int>> root(n+1, vector<int>(n+1));
    vector<vector<double>> w(n+2, vector<double>(n+2));
    vector<vector<double>> e(n+2, vector<double>(n+2));

    for(int i = 1; i <= n; i++) {
        w[i][i-1] = q[i-1];
        e[i][i-1] = q[i-1];
    }

    for(int l = 0; l < n; l++) {
        for(int i = 1; i <= n-l; i++) {
            int j = i + l;
            e[i][j] = MAXVAL;
            w[i][j] = w[i][j-1] + p[j] + q[j];
            for(int r = i; r <= j; r++) {
                double t = e[i][r-1] + e[r+1][j] + w[i][j];
                if(t < e[i][j]) {
                    e[i][j] = t;
                    root[i][j] = r;
                }
            }
        }
    }
    cout << "min cost: "  << e[1][n-1] << endl;
    return root;
}

void print_obst(vector<vector<int>> root, int i, int j) {
    if(j < i) return ;
    int key = root[i][j];
    cout << key << endl;
    print_obst(root, i, key-1);
    print_obst(root, key+1, j);
}

int main() {
    vector<double> p = {0, 0.15, 0.10, 0.05, 0.10, 0.20};
    vector<double> q = {0.05, 0.10, 0.05, 0.05, 0.05, 0.10};
    int n = q.size();
    cout << "p" << ";q" << endl;
    for(int i = 0; i < n; i++) 
        cout << p[i] << ";" << q[i] << endl;

    
    vector<vector<int>> root = obst(n , p, q);
    print_obst(root, 1, n-1);


    p = {0, 0.15, 0.10, 0.05, 0.10};
    q = {0.05, 0.10, 0.05, 0.05, 0.05};
    n = q.size();
    cout << "p" << ";q" << endl;
    for(int i = 0; i < n; i++) 
        cout << p[i] << ";" << q[i] << endl;
    
    root = obst(n , p, q);
    print_obst(root, 1, n-1);

    p = {0, 0.15, 0.10, 0.05, 0.20, 0.20};
    q = {0.05, 0.10, 0.05, 0.15, 0.05, 0.10};
    n = q.size();
    cout << "p" << ";q" << endl;
    for(int i = 0; i < n; i++) 
        cout << p[i] << ";" << q[i] << endl;
    
    root = obst(n , p, q);
    print_obst(root, 1, n-1);
    return 0;
}
