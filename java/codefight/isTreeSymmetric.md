Given a binary tree t, determine whether it is symmetric around its center, i.e. each side mirrors the other.

## Example

For
```
t = {
    "value": 1,
    "left": {
        "value": 2,
        "left": {
            "value": 3,
            "left": null,
            "right": null
        },
        "right": {
            "value": 4,
            "left": null,
            "right": null
        }
    },
    "right": {
        "value": 2,
        "left": {
            "value": 4,
            "left": null,
            "right": null
        },
        "right": {
            "value": 3,
            "left": null,
            "right": null
        }
    }
}
```
the output should be isTreeSymmetric(t) = true.

Here's what the tree in this example looks like:
```
    1
   / \
  2   2
 / \ / \
3  4 4  3
```
As you can see, it is symmetric.

For
```
t = {
    "value": 1,
    "left": {
        "value": 2,
        "left": null,
        "right": {
            "value": 3,
            "left": null,
            "right": null
        }
    },
    "right": {
        "value": 2,
        "left": null,
        "right": {
            "value": 3,
            "left": null,
            "right": null
        }
    }
}
```
the output should be isTreeSymmetric(t) = false.

Here's what the tree in this example looks like:
```
    1
   / \
  2   2
   \   \
   3    3
```
As you can see, it is not symmetric.

## Input/Output

- [time limit] 3000ms (java)
- [input] tree.integer t

A binary tree of integers.

Guaranteed constraints:
```
0 ≤ tree size < 5 · 104,
-1000 ≤ node value ≤ 1000.
```

- [output] boolean

Return true if t is symmetric and false otherwise.
```java
//
// Definition for binary tree:
// class Tree<T> {
//   Tree(T x) {
//     value = x;
//   }
//   T value;
//   Tree<T> left;
//   Tree<T> right;
// }
boolean isTreeSymmetric(Tree<Integer> t) {
    if (t == null) {
        return true;
    }
    return helper(t.left, t.right);
}
boolean helper(Tree<Integer> left, Tree<Integer> right) {
    //base case
    if (left == null && right == null) {
        return true;
    }
    if (left == null || right == null) {
        return false;
    }
    // ask a boolean from left, a boolean from right and return result upwards
    return (left.value.equals(right.value)) && helper(left.left, right.right) && helper(left.right, right.left);
}
```
