/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode node = isCycle(head);
        if(node != null) {
            ListNode step = head;
            while(step != node) {
                step = step.next;
                node = node.next;
            }
        }
        return node;
    }
    
    public ListNode isCycle(ListNode head) {
        if(head == null || head.next == null) return null;
        
        ListNode firstp = head, secondp = head;
        
        while(firstp != null && secondp != null) {
            firstp = firstp.next;
            if(secondp.next == null) return null;
            secondp = secondp.next.next;
            if(firstp == secondp) return firstp;
        }
        return null;
    }
}
