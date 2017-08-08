/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode first = head, second = head;
        int len = 0;
        for(int i = 0; i <= n; i++) {
            if(first == null) break;
            first = first.next;
            len++;
        }
        
        while(first != null) {
            len++;
            first = first.next;
            second = second.next;
        }
        
        if(n == len)  return head.next;
        second.next = second.next.next;       
        return head;
    }
}
