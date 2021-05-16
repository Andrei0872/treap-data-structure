# Treap Data Structure

* test the implementation here: https://www.infoarena.ro/problema/abce

## TODOS

* [X] Find element(print 1 if exists, 0 otherwise)
* [X] Insertion
  * [X] Fulfil BST
  * [X] Do rotations until the priorities are in place
* [ ] Deletion
  * [ ] Find the number
  * [ ] Go downwards while rotating until the node becomes a leaf
  * [ ] Remove the leaf
* [ ] Successor
  * [ ] Right -> Left -> Left...
* [ ] Predecessor
  * [ ] Left -> Right -> Right...
* [ ] Print elements in sorted order: X <= Y <= Z, with X and Y given
  * [ ] In order traversal
* [X] Left & Right Rotations
* [ ] Do not allow duplicates
* [ ] Add comments to functions
* [ ] Document here(###) the reasoning behind each task
* [ ] Refactorings(after it works)

## Description

The challenge is to keep the tree **balanced** as more nodes need to be *added/deleted* from the tree.  
A solution for this is to assign a **randomly generated number**(called *priority*) to each node.

The reason it has to be **balanced** is because when doing rotations, there is a chance that we could end up walking back to the root of the tree and in a **balanced tree** walking back to the root takes at most `O(logN)` steps(since that's the height of the tree).

The reason randomness is used is to ensure the tree remains balanced. For example, if the array we want to construct a *Binary Search Tree* from is in increasing order, then the height of the resulting tree will be `~N`, where `N` is the length of the array. By inserting the numbers in random order, there is a high chance the height of the tree will be about `logN`. In other words, the randomness facilitates the distribution of the elements.

A problem the `Treap` data structure solves is to avoid the height of a *Binary Search Tree* getting too tall. Another benefit of a `Treap` is that it supports `add()` and `delete()` operations, with the help of **rotations**.  
By doing rotations, we ensure the **priority** of each node in the `Treap` is kept.

### The 2 main condition a `Treap` must satisfy

* this tree structure needs to satisfy 2 conditions
  * the **BST rule**: for a given node, all the nodes' values from the left subtree are smaller than the root's value and the all the nodes' values from the right subtree are greater than the root's value
  * the **Heap rule**: for a *min-heap* the priority of the root is less than the priority of its children and vice versa for *max-heap*

### Inserting a node

* insert the value as per **BST**
* if the node's priority is greater(*max-heap*)/smaller(*min-heap*) than the parent's, do tree rotations until it's fixed
* complexity: `O(logN)` to insert the node and another `O(logN)` to do the rotations

### Deleting a node

* TODO: explain why we're always *choosing* the children with smaller priority
```cpp
if (node.left.p < node.right.p) {
  rotateRight(node);
} else {
  rotateLeft(node);
}
```

---

## References

* https://www.youtube.com/watch?v=uwWOUAdOTig
* https://www.youtube.com/watch?v=6x0UlIBLRsc
* https://opendatastructures.org/ods-java/7_2_Treap_Randomized_Binary.html
* http://faculty.cs.niu.edu/~freedman/340/340notes/340treap.htm