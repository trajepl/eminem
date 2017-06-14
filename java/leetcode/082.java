/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        while(head != null && head.next != null && head.next.val == head.val) {
            int headVal = head.val;
            while(head != null && head.val == headVal) head = head.next;
        }
        
        if(head == null) return head;
        
        ListNode ptLeft = head;
        ListNode ptRight = head;
        int ptLeftVal = ptLeft.val;
        
        while(ptRight.next != null) {
            ptRight = ptRight.next;
            while (ptRight != null && ptRight.val == ptLeftVal) {
                ptRight = ptRight.next;
            }
            ptLeft.next = ptRight;
            if(ptRight == null) break;
            if(ptLeft.next.next != null && ptLeft.next.next.val != ptLeft.next.val) {
                ptLeft = ptLeft.next;
            }
            ptLeftVal = ptRight.val;
        }
        return head;
    }
}

public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null) return head;
        
        ListNode dummy = new ListNode(0);
        ListNode first = head, cur = head.next, pre = dummy;
        dummy.next = head;

        while (cur != null) {
            if (first.val == cur.val) {
                pre.next = cur.next;
            } else {
                if (first.next == cur) {
                    pre = pre.next;
                }
                first = cur;
            }
            cur = cur.next;
        }
        return dummy.next;
    }
}
