#include <iostream>
#include <vector>

using namespace std;

int award(int score1, int score2, bool role, bool position, int paper) {
    int res = 0;
    if (score1 > 80 && paper >= 1) {
        res += 8000;
    }
    if (score1 > 85 && score2 > 80) {
        res += 4000;
    }
    if (score1 > 90) {
        res += 2000;
    }
    if (score1 > 85 && position) {
        res += 1000;
    }
    if (score2 > 80 && role) {
        res += 850;
    }
    return res;
}

int main() {
    int n; cin >> n;
    string name, res_name;
    char role, position;
    int score1, score2, paper ;
    int sum_award = 0;
    int res_award = 0;
    for (int i = 0; i < n; ++i) {
        cin >> name >> score1 >> score2 >> role >> position >> paper;
        int award_t = award(score1, score2, role=='Y', position=='Y', paper); 
        sum_award += award_t;
        if (award_t > res_award) {
            res_name = name;
            res_award = award_t; 
        }
    }
    cout << res_name << endl << res_award << endl << sum_award << endl;
    return 0;
}
