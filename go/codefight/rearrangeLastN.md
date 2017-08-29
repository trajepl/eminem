Note: Try to solve this task in O(list size) time using O(1) additional space, since this is what you'll be asked during an interview.

Given a singly linked list of integers l and a non-negative integer n, move the last n list nodes to the beginning of the linked list.

## Example

For l = [1, 2, 3, 4, 5] and n = 3, the output should be
rearrangeLastN(l, n) = [3, 4, 5, 1, 2];
For l = [1, 2, 3, 4, 5, 6, 7] and n = 1, the output should be
rearrangeLastN(l, n) = [7, 1, 2, 3, 4, 5, 6].
## Input/Output

- [time limit] 4000ms (go)
- [input] linkedlist.integer l

A singly linked list of integers.

Guaranteed constraints:
```
0 ≤ list size ≤ 105,
-1000 ≤ element value ≤ 1000.
```

- [input] integer n

A non-negative integer.

Guaranteed constraints:
```
0 ≤ n ≤ list size.
```

- [output] linkedlist.integer

Return l with the n last elements moved to the beginning.

```java
// Definition for singly-linked list:
// type ListNode struct {
//   Value interface{}
//   Next *ListNode
// }
//
func rearrangeLastN(l *ListNode, n int) *ListNode {
    if l == nil || n == 0 { return l }
    var p, q, flag *ListNode
    p, q, flag = l, l, l
    
    i := 1
    
    for p.Next != nil {
        i++
        p = p.Next
        
        if(i > n+1) {
            q = q.Next
        }
    }
    
    if i == n { return l }
    head := q.Next
    q.Next = nil
    p.Next = flag
    
    return head
}
```
