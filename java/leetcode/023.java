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

public class Solution {
    public ListNode mergeKLists(List<ListNode> lists) {
        if (lists==null||lists.size()==0) return null;

        PriorityQueue<ListNode> queue= new PriorityQueue<ListNode>(
            lists.size(),new Comparator<ListNode>(){
                @Override
                public int compare(ListNode o1,ListNode o2){
                    if (o1.val<o2.val)
                        return -1;
                    else if (o1.val==o2.val)
                        return 0;
                    else
                        return 1;
                }
            } 
        );

        ListNode dummy = new ListNode(0);
        ListNode tail=dummy;

        for (ListNode node:lists)
            if (node!=null)
                queue.add(node);

        while (!queue.isEmpty()){
            tail.next=queue.poll();
            tail=tail.next;

            if (tail.next!=null)
                queue.add(tail.next);
        }
        return dummy.next;
    }
}

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        return partition(lists, 0, lists.length - 1);
    }
    public ListNode partition(ListNode[] lists, int s, int e) {
        if(s == e) return lists[s];
        if (s < e) {
            int mid = (e + s) / 2;
            ListNode l1 = partition(lists, s, mid);
            ListNode l2 = partition(lists, mid+1, e);
            return merge(l1, l2);
        } else {
            return null;
        }
    }
    public ListNode merge(ListNode l1, ListNode l2) {
        if (l1 == null) return l2;
        if (l2 == null) return l1;
        if (l1.val < l2.val){
            l1.next = merge(l1.next, l2);
            return l1;
        } else {
            l2.next = merge(l1, l2.next);
            return l2;
        }
    }
}
