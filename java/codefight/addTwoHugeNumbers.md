You're given 2 huge integers represented by linked lists. Each linked list element is a number from 0 to 9999 that represents a number with exactly 4 digits. The represented number might have leading zeros. Your task is to add up these huge integers and return the result in the same format.

## Example

For a = [9876, 5432, 1999] and b = [1, 8001], the output should be
addTwoHugeNumbers(a, b) = [9876, 5434, 0].

Explanation: 987654321999 + 18001 = 987654340000.

For a = [123, 4, 5] and b = [100, 100, 100], the output should be
addTwoHugeNumbers(a, b) = [223, 104, 105].

Explanation: 12300040005 + 10001000100 = 22301040105.

## Input/Output

- [time limit] 4000ms (go)
- [input] linkedlist.integer a

The first number, without its leading zeros.

Guaranteed constraints:
```
0 ≤ a size ≤ 104,
0 ≤ element value ≤ 9999.
```
- [input] linkedlist.integer b

The second number, without its leading zeros.

Guaranteed constraints:
```
0 ≤ b size ≤ 104,
0 ≤ element value ≤ 9999.
```

- [output] linkedlist.integer

The result of adding a and b together, returned without leading zeros in the same format.

```java
// Definition for singly-linked list:
// class ListNode<T> {
//   ListNode(T x) {
//     value = x;
//   }
//   T value;
//   ListNode<T> next;
// }
//
ListNode<Integer> addTwoHugeNumbers(ListNode<Integer> a, ListNode<Integer> b) {
    BigInteger sum = parseLong(a).add(parseLong(b));
    System.out.println(sum);
    ListNode<Integer> ret = null;
    
    if(sum.compareTo(new BigInteger("0")) == 0) return new ListNode<>(0);
    
    while(sum.compareTo(new BigInteger("0")) > 0) {
        ListNode<Integer> node = new ListNode<>(null);
        node.value = Integer.parseInt(sum.mod(new BigInteger("10000")).toString());
        System.out.println(node.value);
        sum = sum.divide(new BigInteger("10000"));
        node.next = ret;
        ret = node;
    }
    
    return ret;
}

BigInteger parseLong(ListNode<Integer> a) {
    BigInteger ret = new BigInteger("0");
    while(a != null) {
        ret = ret.multiply(new BigInteger("10000"));
        ret = ret.add(new BigInteger(a.value+""));
        a = a.next;
    }
    return ret;
}
```

```java
ListNode<Integer> addTwoHugeNumbers(ListNode<Integer> a, ListNode<Integer> b) {

    ListNode<Integer> reversedA = reverse(a);
    ListNode<Integer> reversedB = reverse(b);
    ListNode<Integer> result = null;
    int residual = 0;
    
    while(reversedA != null || reversedB != null){
        int valA = 0;
        int valB = 0;
        
        if(reversedA != null){
            valA = reversedA.value;
            reversedA = reversedA.next;
        }
        
        if(reversedB != null){
            valB = reversedB.value;
            reversedB = reversedB.next;
        }
        
        int sum = valA + valB + residual;

        result = add(sum%10000, result);

        residual = sum /10000;
        
    }
    if(residual != 0)
        result = add(residual, result);
    return reverse(result);
}

ListNode<Integer> add(int n, ListNode<Integer> head){
    if(head == null){
        head = new ListNode<Integer>(n);
        return head;
    }
    ListNode<Integer> temp = head;

    while(temp.next != null){
        temp = temp.next;
    }
    temp.next = new ListNode<Integer>(n);
    return head;
}

ListNode<Integer> reverse(ListNode<Integer> node) {
    ListNode<Integer> prev = null;
    ListNode<Integer> current = node;
    ListNode<Integer> next = null;
    while (current != null) {
        next = current.next;
        current.next = prev;
        prev = current;
        current = next;
    }
    node = prev;
    return node;
}
```
