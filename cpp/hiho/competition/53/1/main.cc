#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

#include <stdio.h>
#include <string.h>

using namespace std;

struct Node {
    int sta = 1;
    vector<string> pt;
};

void dfs(unordered_map<string, Node> tree, string king, bool is_king) {
    Node node = tree[king];
    vector<string> child = node.pt;
    if(!is_king && node.sta)
        cout << king << endl;

    for(int i = 0; i < child.size(); i++) {
        dfs(tree, child[i], false);
    }
}

vector<string> split_c(string s, const char * delimit) {
    vector<string> line;
    char *p = strtok((char *)s.c_str(), delimit);
    vector<string> line_d;
    while(p != NULL) {
        line.push_back(string(p));
        p = strtok(NULL, " ");
    }
    return line;
}

vector<string> split(string s) {
    vector<string> line;
    string a;
    for(istringstream sin(s); sin >> a; line.push_back(a));
    return line;
}

int main() {
    int n; cin >> n;
    string king; cin >> king;
    unordered_map<string, Node> map_node;
    map_node[king] = Node();
    string t;
    getline(cin, t);
    
    while(n-- > 0) {
        string line;
        getline(cin, line);
        
        vector<string> line_d = split(line);
        int sta = (line_d[0] == "birth") ? 1 : 0; 
        map_node[line_d[1]].sta = sta;
        if(sta) {
            map_node[line_d[1]].pt.push_back(line_d[2]);
            map_node[line_d[2]] = Node();
        }
    }

    dfs(map_node, king, true);

    return 0;
}
