#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

ListNode *addFront(ListNode *p, int val) {
    ListNode *node = new ListNode(val);
    node->next = p;
    return node;
}

void print_linked(ListNode *p) {
    while (p != NULL) {
        cout << p->val << endl;
        p = p->next;
    }
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int len1 = 0, len2 = 0;
    ListNode *cur1 = l1, *cur2 = l2;
    while (cur1 != NULL) {cur1 = cur1->next; len1++;}
    while (cur2 != NULL) {cur2 = cur2->next; len2++;}
    cur1 = l1; cur2 = l2;

    ListNode *p = nullptr;
    while (len1 > 0 && len2 > 0) {
        int sum = 0;
        if (len1 > len2) {
            sum = cur1->val;
            cur1 = cur1->next;
            len1--;
        } else if (len1 < len2) {
            sum = cur2->val;
            cur2 = cur2->next;
            len2--;
        } else {
            sum = cur1->val + cur2->val;
            cur1 = cur1->next;
            cur2 = cur2->next;
            len1--; len2--;
        }
        p = addFront(p, sum);
    }

    int t = 0;
    ListNode *node = p; p = nullptr;
    while (node != NULL) {
        int val = node->val + t;
        int merchat = val / 10;
        int remainder = val % 10;
        p = addFront(p, remainder);
        ListNode *temp = node;
        node = node ->next;
        t = merchat;
        delete temp;
    }
    
    if (t) p = addFront(p, 1);
    return p;
}


int main() {
    ListNode *l1 = new ListNode(7);
    ListNode *lt1 = l1;
    l1->next = new ListNode(2);
    l1 = l1->next;
    l1->next = new ListNode(4);
    l1 = l1->next;
    l1->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    ListNode *lt2 = l2;
    l2->next = new ListNode(6);
    l2 = l2->next;
    l2->next = new ListNode(4);

    ListNode *l = addTwoNumbers(lt1, lt2);
    print_linked(l);
    return 0;
}
