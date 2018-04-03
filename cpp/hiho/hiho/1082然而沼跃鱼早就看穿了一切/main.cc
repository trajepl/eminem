#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const string s = "marshtomp";
const string s_r = "fjxmlhx";

int main() {
    size_t len_s = s.size();
    size_t len_sr = s_r.size();

    string t;
    while (getline(cin, t)) {
        string low = t;
        transform(low.begin(), low.end(), low.begin(), ::tolower);

        size_t pos = low.find(s);
        while(pos != string::npos) {
            t = t.replace(pos, len_s, s_r);
            low = low.replace(pos, len_s, s_r );
            pos = low.find(s);
        }
        cout << t << endl;
    }
        
    return 0;
}
