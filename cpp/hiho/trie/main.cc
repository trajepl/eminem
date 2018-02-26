// Trie tree
#include <iostream>
#include <vector>
#include <string>

#define CHARNUM 26
#define BASE 'a'

using namespace std;

typedef struct node {
    int child_num = 0;
    struct node *point[CHARNUM];
}Node;

typedef struct trie {
    Node *root = new Node();
    void add(string s) {
        //root->point[s[0] - BASE] = new Node();
        //root->child_num++;

        Node *node = root;
        string::iterator it;
        for(it = s.begin(); it < s.end(); it++) {
            if(node->point[*it-BASE] == NULL) {
                node->point[*it-BASE] = new Node();
            }
            node = node->point[*it-BASE];
            node->child_num++;
        }
    }

    int query(string s) {
        string::iterator it;
        Node *node = root;
        bool flag = true;
        for(it = s.begin(); it < s.end(); it++) {
            if(node->point[*it - BASE] == NULL) {
                flag = false;
                break;
            } else {
                node = node->point[*it - BASE];
            }
        }
        if(flag) return node->child_num;
        return 0;
    }
}Trie;

int main() {
    Trie trie;
    int n;
    cin >> n;
    cin.get();

    while(n-- > 0) {
        string s;
        getline(cin, s);
        trie.add(s);
    }

    cin >> n;
    cin.get();
    while(n-- > 0) {
        string s;
        getline(cin, s);
        cout << trie.query(s) << endl;
    }
    return 0;
}
