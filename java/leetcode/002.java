/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
	public ListNode addTwoNumber(ListNode l1, ListNode l2) {
		int flag_in = 0, tmp = 0;
		ListNode flag = new ListNode(-1), ret;
		ListNode head = flag;

		while(l1 != null && l2 != null) {
			tmp = l1.val + l2.val + flag_in;
			ret = new ListNode(tmp % 10);
			flag.next = ret;
			flag = flag.next;
			flag_in = tmp / 10;
			l1 = l1.next; l2 = l2.next;
		}
		if(l1 != null) {
			while(l1 != null) {
				tmp = l1.val + flag_in;
				ret = new ListNode(tmp % 10);
				flag.next = ret;
				flag = flag.next;
				flag_in = tmp / 10;
				l1 = l1.next;
			}
			if(flag_in != 0) flag.next = new ListNode(flag_in);
			return head.next;
		} else if(l2 != null) {
			while(l2 != null) {
				tmp = l2.val + flag_in;
				ret = new ListNode(tmp % 10);
				flag.next = ret;
				flag = flag.next;
				flag_in = tmp % 10;
				l2 = l2.next;
			}
			if(flag_in != 0) flag.next = new ListNode(flag_in);
			return head.next;
		} else {
			if(flag_in != 0) flag.next = new ListNode(flag_in);
			return head.next;
		}
	} 

}
