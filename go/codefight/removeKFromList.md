Note: Try to solve this task in O(n) time using O(1) additional space, where n is the number of elements in the list, since this is what you'll be asked to do during an interview.

Given a singly linked list of integers l and an integer k, remove all elements from list l that have a value equal to k.

## Example

For l = [3, 1, 2, 3, 4, 5] and k = 3, the output should be
removeKFromList(l, k) = [1, 2, 4, 5];
For l = [1, 2, 3, 4, 5, 6, 7] and k = 10, the output should be
removeKFromList(l, k) = [1, 2, 3, 4, 5, 6, 7].
## Input/Output

- [time limit] 4000ms (go)
- [input] linkedlist.integer l

A singly linked list of integers.

Guaranteed constraints:
```
0 ≤ list size ≤ 105,
-1000 ≤ element value ≤ 1000.
0 ≤ list size ≤ 105,
```
- [input] integer k

An integer.

Guaranteed constraints:
```
-1000 ≤ k ≤ 1000.
```

- [output] linkedlist.integer

Return l with all the values equal to k removed.

```go
// Definition for singly-linked list:
// type ListNode struct {
//   Value interface{}
//   Next *ListNode
// }
//
func removeKFromList(l *ListNode, k int) *ListNode {
    h := &ListNode{}
    h.Next = l
    l = h
    for l.Next != nil {
         if l.Next.Value == k {
            l.Next = l.Next.Next
         } else {
            l = l.Next
         }

    }
    return h.Next
}

```
