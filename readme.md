# Treap Data Structure

*You can test the implementation [here](https://www.infoarena.ro/problema/abce).*

- [Treap Data Structure](#treap-data-structure)
  - [Description](#description)
  - [The 2 main condition a `Treap` must satisfy](#the-2-main-condition-a-treap-must-satisfy)
    - [The `BST` rule](#the-bst-rule)
    - [The `Heap` rule](#the-heap-rule)
  - [Operations in `Treap`](#operations-in-treap)
    - [Inserting a node](#inserting-a-node)
    - [Deleting a node](#deleting-a-node)
    - [Searching for a node](#searching-for-a-node)
    - [Finding the successor for a given value](#finding-the-successor-for-a-given-value)
    - [Finding the predecessor for a given value](#finding-the-predecessor-for-a-given-value)
    - [Printing items in ascending order between 2 boundaries](#printing-items-in-ascending-order-between-2-boundaries)
  - [infoarena results](#infoarena-results)
  - [References](#references)

## Description

The challenge is to keep the tree **balanced** as more nodes need to be **added/deleted** from the tree. Otherwise, operations like *finding a node* might end up having the complexity of `O(n)`. An example would be the case where in a binary tree numbers are inserted in ascending/descending order.  
A solution for this is to assign a **randomly generated number**(called *priority*) to each node.

The reason it has to be **balanced** is because when doing rotations, there is a chance that we could end up walking back to the root of the tree and in a **balanced tree** walking back to the root takes at most `O(logN)` steps(since that's the height of the tree).

The reason randomness is used is to ensure the tree remains balanced. For example, if the array we want to construct a *Binary Search Tree* from is in increasing order, then the height of the resulting tree will be `~N`, where `N` is the length of the array. By inserting the numbers in random order, there is a high chance the height of the tree will be about `logN`. In other words, the randomness facilitates the distribution of the elements.

A problem the `Treap` data structure solves is to avoid a *Binary Search Tree* getting too tall. Another benefit of a `Treap` is that it supports `add()` and `delete()` operations, with the help of **rotations**.  
By doing rotations, we ensure the **priority** of each node in the `Treap` is kept.

---

## The 2 main condition a `Treap` must satisfy

### The `BST` rule

For a given node, all the nodes' values from the **left subtree** are **smaller** than the root's value and all the nodes' values from the **right subtree** are **greater** than the root's value.

### The `Heap` rule

For a *Min Heap*, the priority of the root is less than the priority of its children and vice versa for a *Max Heap*.

**Note**: this implementation is based on a *Min Heap*.

---

## Operations in `Treap`

### Inserting a node

1. Inserting the value as per **BST**

2. If the node's priority is greater(for a *Max Heap*)/smaller(for a *Min Heap*) than the parent's, do tree rotations until everything is fixed

The complexity is `O(logN)` to insert the node and another `O(logN)` to do the rotations.

### Deleting a node

1. Finding the node which holds the given value

2. Going downwards until the node that is to be deleted becomes a **leaf**.  
   The rationale behind this is the following: suppose the node we want to delete is anywhere in the tree, then there are four cases:
    * the node is a leaf, nothing to do from here
    * `node.right == NULL`, case in which we do a **right rotation**
    * `node.left == NULL`, case in which we do a **left rotation**
    * if `node.left.priority < node.right.priority`, then we do a **right rotation**, otherwise we do a **left rotation**; the reason behind this is that we always want the parent node to be *replaced* with a node(one of this children) which has a **lower priority**, since this implementation is based on a *Min Heap*

3. Removing the leaf

### Searching for a node

In this situation, the concepts for a *Binary Search Tree* are applied.

### Finding the successor for a given value

For a given value `X`, it is known that the successor's value(`V`) will be greater than or equal to to `X`. The solution is to traverse the `Treap`, similarly to how it would be traversed in case of insertion, but for each node we check if the difference `X-V` is greater than or equal to `0`, and if that's the case, that node is saved as the *current successor*.  
It keeps traversing until there is nothing left to traverse.

### Finding the predecessor for a given value

The same process as above is applied here, with the exception that the difference between `X-V` must be greater than or equal to `0`.

### Printing items in ascending order between 2 boundaries

It is done an *inorder traversal*, so that nodes are traversed in ascending order, but instead of printing out the value, it checked if it is within the given boundaries and if that's the case, it is written into the output file.

---

## infoarena results

The results can be found [here](https://www.infoarena.ro/job_detail/2752005).

As can be noticed, the final score is `50`(out of `100`) and for **all** the cases that failed, the time limit(`400ms`) has been exceeded by **only** `0ms`, `1ms`, `2ms` or `3ms`.

---

## References

* [Treap (Tree + Heap) Data Structure - Tutorial with Statistical Analysis](https://www.youtube.com/watch?v=uwWOUAdOTig)
* [AlgorithmsThread 9: Treaps!](https://www.youtube.com/watch?v=6x0UlIBLRsc)
* [7.2 Treap: A Randomized Binary Search Tree](https://opendatastructures.org/ods-java/7_2_Treap_Randomized_Binary.html)
* [Treaps](http://faculty.cs.niu.edu/~freedman/340/340notes/340treap.htm)