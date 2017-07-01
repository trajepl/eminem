/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        int lena = length(headA), lenb = length(headB);
        
        while(lena > lenb) {
            headA = headA.next;
            lena--;
        }
        while(lenb > lena) {
            headB = headB.next;
            lenb--;
        }
        
        while(headA != headB) {
            headA = headA.next;
            headB = headB.next;
        }
        
        return headA;
    }
    
   	public int length(ListNode head) {
        int i = 0;
        while(head != null) {
            head = head.next;
            i++;
        }
        return i;
	}
}
