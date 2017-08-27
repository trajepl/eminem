Note: Try to solve this task in O(n) time using O(1) additional space, where n is the number of elements in l, since this is what you'll be asked to do during an interview.

Given a singly linked list of integers, determine whether or not it's a palindrome.

## Example

For l = [0, 1, 0], the output should be
isListPalindrome(l) = true;
For l = [1, 2, 2, 3], the output should be
isListPalindrome(l) = false.
## Input/Output

- [time limit] 4000ms (go)
- [input] linkedlist.integer l

A singly linked list of integers.

Guaranteed constraints:
```
0 ≤ list size ≤ 5 · 105,
-109 ≤ element value ≤ 109.
```

- [output] boolean

Return true if l is a palindrome, otherwise return false.

```go
// Definition for singly-linked list:
// type ListNode struct {
//   Value interface{}
//   Next *ListNode
// }
//
func isListPalindrome(head *ListNode) bool {
    if head == nil || head.Next == nil { return true }
    slow, fast := head, head
    var prev, next, first, second *ListNode
    for fast != nil && fast.Next != nil {
        fast = fast.Next.Next
        next = slow.Next
        slow.Next = prev
        prev = slow
        slow = next
    }
    if fast == nil { second = slow } else { second = slow.Next }
    first = prev
    for first != nil {
        if first.Value.(int) != second.Value.(int) { return false }
        first, second = first.Next, second.Next
    }
    return true
}
```
