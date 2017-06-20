/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        Queue<ListNode> q = new LinkedList<>();
        
        for(ListNode node: lists) {
            q.offer(node);
        }
        while(q.size() > 1) {
            ListNode tmp1 = q.poll();
            ListNode tmp2 = q.poll();
            q.offer(merge(tmp1, tmp2));
        }
        return q.poll();
    }
    public ListNode merge(ListNode l1, ListNode l2) {
        if(l1 == null) return l2;
        if(l2 == null) return l1;
        
        if(l1.val > l2.val) return merge(l2, l1);
        ListNode head = l1;
        l1.next = merge(l1.next, l2);
        return head;
    }
}
