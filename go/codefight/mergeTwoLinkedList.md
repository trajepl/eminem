```java
// Definition for singly-linked list:
// type ListNode struct {
//   Value interface{}
//   Next *ListNode
// }
//
func mergeTwoLinkedLists(l1 *ListNode, l2 *ListNode) *ListNode {
    head := &ListNode{}
    ret := head
    
    for l1 != nil && l2 != nil {
        if l1.Value.(int) > l2.Value.(int) {
            head.Next = l2
            head = head.Next
            l2 = l2.Next
        } else {
            head.Next = l1
            head = head.Next
            l1 = l1.Next
        }
    }
    
    if l1 == nil { head.Next = l2 }
    if l2 == nil { head.Next = l1 }
    
    return ret.Next
}
```
