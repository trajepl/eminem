/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    static bool cmp(ListNode* a, ListNode* b) {
        return a->val < b->val;
    }

    // brute force
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> vec = vector<ListNode*>();
        for (auto it: lists) {
            ListNode* head = it;
            while (head != nullptr) {
                vec.emplace_back(head);
                head = head->next;
            }
        }
        if (vec.size() <= 0) return nullptr;
        sort(vec.begin(), vec.end(), cmp);
        ListNode* head = vec[0];
        ListNode* cur = head;
        for (int i = 1; i < vec.size(); ++i) {
            cur->next = vec[i];
            cur = cur->next;
        }
        cur->next = nullptr;
        return head;
    }


    // priority_queue
    struct cmp_pointer {
        bool operator() (ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp_pointer> pq;
        for (auto it: lists) {
            ListNode * ptr = it;
            while (ptr != nullptr) {
                pq.push(ptr);
                ptr = ptr->next;
            }
        }
        if (pq.size() <= 0) return nullptr;
        ListNode* head = pq.top(); pq.pop();
        ListNode* cur = head;
        while (pq.size() > 0) {
            ListNode* _cur = pq.top(); pq.pop();
            cur->next = _cur;
            cur = cur->next;
        }
        cur->next = nullptr;
        return head;
    }
};
