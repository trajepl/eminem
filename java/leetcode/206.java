/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode reverseList(ListNode head) {
        
        ListNode prev = null;
        
        while(head != null){
            ListNode record = head.next;
            head.next = prev;
            prev = head;
            head = record;
        }
        
        return prev;
    }
}
