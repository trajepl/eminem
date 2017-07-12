/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode sortList(ListNode head) {
        if(head == null || head.next == null) return head;
        // cut 
        ListNode slow = head, fast = head;
        while(fast.next != null && fast.next.next != null) {
            fast = fast.next.next;
            slow = slow.next;
        }
        ListNode l1 = head, l2 = slow.next;
        slow.next = null;
        
        // merge sort
        l1 = sortList(l1);
        l2 = sortList(l2);
        
        return merge(l1, l2);
    }
    
    public void printListNode(ListNode head) {
        while(head != null) {
            System.out.println(head.val);
            head = head.next;
        }
    }
    public ListNode merge(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(-1), tmp = head;
        
        while(l1 != null && l2 != null) {
            if(l1.val < l2.val) {
                head.next = l1;
                l1 = l1.next;
            } else {
                head.next = l2;
                l2 = l2.next;
            }
            head = head.next;
        }
        if(l1 != null) head.next = l1;
        if(l2 != null) head.next = l2;
        
        return tmp.next;
    }
}
