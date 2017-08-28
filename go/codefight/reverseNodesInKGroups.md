Note: Your solution should have O(n) time complexity, where n is the number of element in l, and O(1) additional space complexity, since this is what you would be asked to accomplish in an interview.

Given a linked list l, reverse its nodes k at a time and return the modified list. k is a positive integer that is less than or equal to the length of l. If the number of nodes in the linked list is not a multiple of k, then the nodes that are left out at the end should remain as-is.

You may not alter the values in the nodes - only the nodes themselves can be changed.

## Example

For l = [1, 2, 3, 4, 5] and k = 2, the output should be
reverseNodesInKGroups(l, k) = [2, 1, 4, 3, 5];
For l = [1, 2, 3, 4, 5] and k = 1, the output should be
reverseNodesInKGroups(l, k) = [1, 2, 3, 4, 5];
For l = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11] and k = 3, the output should be
reverseNodesInKGroups(l, k) = [3, 2, 1, 6, 5, 4, 9, 8, 7, 10, 11].
## Input/Output

- [time limit] 4000ms (go)
- [input] linkedlist.integer l

A singly linked list of integers.

Guaranteed constraints:
```
1 ≤ list size ≤ 104,
-109 ≤ element value ≤ 109.
```

- [input] integer k

The size of the groups of nodes that need to be reversed.

Guaranteed constraints:
1 ≤ k ≤ l size.

- [output] linkedlist.integer

The initial list, with reversed groups of k elements.
```go
// Definition for singly-linked list:
// type ListNode struct {
//   Value interface{}
//   Next *ListNode
// }
//
func reverseNodesInKGroups(l *ListNode, k int) *ListNode {
    if k == 1 { return l }
    
    len_list := 0
    node_l := l
    for node_l != nil {
        node_l = node_l.Next
        len_list++
    }
    
    
    head_tmp := &ListNode{}
    crossing := &ListNode{}
    ret := l
    for i := 0; i < len_list / k; i++ {
        j := k
        head := &ListNode{}
        for j > 0 {
            j--
            tmp := l.Next
            l.Next = head
            head = l
            l = tmp
        }
        ret.Next = l 
        
        if i == 0 {
            head_tmp = head
        } else {
            crossing.Next = head
        }
        
        crossing = ret
        ret = l
    }
    
    
    return head_tmp
}
```
