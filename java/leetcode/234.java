/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public boolean isPalindrome(ListNode head) {
        if(head == null) return true;
        int len = length(head);
        int mid = len / 2;
        if(len % 2 == 0) mid--;
    	
        ListNode pre = null;
        while(mid >= 0) {
            ListNode tmp = head.next;
            head.next = pre;
            pre = head;
            head = tmp;
            mid--;
        }
        if(len % 2 != 0) pre = pre.next;
        while(pre != null) {
            if(pre.val != head.val) return false;
            pre = pre.next;
            head = head.next;
		}
        
        return true;
    }
    
    
    public int length(ListNode head) {
        int i = 0;
        while(head != null) {
            i++;
            head = head.next;
        }
        return i;
	}

    public boolean isPalindrome(ListNode head) {
        ListNode fast = head, slow = head;
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
        }
        if (fast != null) { // odd nodes: let right half smaller
            slow = slow.next;
        }
        slow = reverse(slow);
        fast = head;

        while (slow != null) {
            if (fast.val != slow.val) {
                return false;
            }
            fast = fast.next;
            slow = slow.next;
        }
        return true;
    }

    public ListNode reverse(ListNode head) {
        ListNode prev = null;
        while (head != null) {
            ListNode next = head.next;
            head.next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
}
