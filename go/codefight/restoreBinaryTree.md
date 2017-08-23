Note: Your solution should have O(inorder.length) complexity, since this is what you will be asked to accomplish in an interview.

Let's define inorder and preorder traversals of a binary tree as follows:

- Inorder traversal first visits the left subtree, then the root, then its right subtree;
- Preorder traversal first visits the root, then its left subtree, then its right subtree.
For example, if tree looks like this:
```
    1
   / \
  2   3
 /   / \
4   5   6
```
then the traversals will be as follows:

Inorder traversal: [4, 2, 1, 5, 3, 6]
Preorder traversal: [1, 2, 4, 3, 5, 6]
Given the inorder and preorder traversals of a binary tree t, but not t itself, restore t and return it.

## Example

For inorder = [4, 2, 1, 5, 3, 6] and preorder = [1, 2, 4, 3, 5, 6], the output should be
```
restoreBinaryTree(inorder, preorder) = {
    "value": 1,
    "left": {
        "value": 2,
        "left": {
            "value": 4,
            "left": null,
            "right": null
        },
        "right": null
    },
    "right": {
        "value": 3,
        "left": {
            "value": 5,
            "left": null,
            "right": null
        },
        "right": {
            "value": 6,
            "left": null,
            "right": null
        }
    }
}
```
For inorder = [2, 5] and preorder = [5, 2], the output should be
```
restoreBinaryTree(inorder, preorder) = {
    "value": 5,
    "left": {
        "value": 2,
        "left": null,
        "right": null
    },
    "right": null
}
```
## Input/Output

- [time limit] 4000ms (go)
- [input] array.integer inorder

An inorder traversal of the tree. It is guaranteed that all numbers in the tree are pairwise distinct.

Guaranteed constraints:
```
1 ≤ inorder.length ≤ 2 · 103,
-105 ≤ inorder[i] ≤ 105.
```

- [input] array.integer preorder

A preorder traversal of the tree.

Guaranteed constraints:
```
preorder.length = inorder.length,
-105 ≤ preorder[i] ≤ 105.
```

- [output] tree.integer

The restored binary tree.

```go
//
// Definition for binary tree:
// type Tree struct {
//   Value interface{}
//   Left *Tree
//   Right *Tree
// }

func restoreBinaryTree(inorder []int, preorder []int) *Tree {
	if len(inorder) == 0 {
		return nil
	}

	root := preorder[0]

	for i, v := range inorder {
		if v == root {
			return &Tree{
				root,
				restoreBinaryTree(inorder[:i], preorder[1:i+1]),
				restoreBinaryTree(inorder[i+1:], preorder[i+1:]),
			}
		}
	}

	return nil
}
 
```
