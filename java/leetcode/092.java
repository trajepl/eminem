/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
// 4ms
public class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if(m == n) return head;
        int cnt = 0;
        
        ListNode tmp = null, newHead = head;
        ListNode nodeM = null, tailNode = null;
        
        while(cnt++ < n) {
            ListNode node = head.next;
            if(cnt == m - 1) nodeM = head;
            if(cnt >= m) {
                if(cnt == m) tailNode = head;
                head.next= tmp;              
                tmp = head;
            }
            head = node;                 
        }
        tailNode.next = head;
        if(m == 1) return tmp;
        else nodeM.next = tmp;
        return newHead;
    }
}

// 0ms
public class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if (head == null || m >= n) {
            return head;
        }

        ListNode sentinel = new ListNode(-1);
        sentinel.next = head;
        ListNode node = sentinel;

        // move the "node" pointer in front of the m-th node
        for (int i = 1; i < m; ++i) {
            node = node.next;
        }

        // reverse nodes
        ListNode curr = node.next;
        for (int i = m; i < n; ++i) {
            ListNode temp = node.next;
            node.next = curr.next;
            curr.next = curr.next.next;
            node.next.next = temp;
        }

        return sentinel.next;
    }
}
