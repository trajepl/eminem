/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1 == null) return l2;
        if(l2 == null) return l1;
        ListNode newNode = null;
        if(l1.val < l2.val) newNode = l1;
        else newNode = l2;
        while(l1 != null && l2 != null) {
            ListNode flag = null;
            if(l1.val < l2.val) {
                while(l1.next != null && l1.next.val < l2.val){
                    l1 = l1.next;
                } 
                flag = l1.next;
                l1.next = l2;
                l1 = flag;
            } else {
                while(l2.next != null && l2.next.val <= l1.val) {
                    l2 = l2.next;
                }
                flag = l2.next;
                l2.next = l1;
                l2 = flag;
            }
        }
        return newNode;
    }
}

public class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1 == null){
            return l2;
        }
        if(l2 == null){
            return l1;
        }
        if (l1.val > l2.val) {return  mergeTwoLists(l2, l1);}
        ListNode dummy = l1;
        l1.next = mergeTwoLists(l1.next, l2);
        return dummy;
    }
}
