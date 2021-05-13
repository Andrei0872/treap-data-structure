# Treap Data Structure

* test the implementation here: https://www.infoarena.ro/problema/abce

## TODOS

* [ ] cautare
* [ ] inserare
* [ ] ștergere
* [ ] succesor
* [ ] predecesor
* [ ] afisare elemente sortat

## Description

The challenge is to keep the tree **balanced** as more nodes need to be *added/deleted* from the tree.  
A solution for this is to assign a **randomly generated number**(called *priority*) to each node.

The reason it has to be **balanced** is because when doing rotations, there is a chance that we could end up walking back to the root of the tree and in a **balanced tree** walking back to the root takes at most `O(logN)` steps(since that's the height of the tree).

The reason randomness is used is to ensure the tree remains balanced. For example, if the array we want to construct a *Binary Search Tree* from is in increasing order, then the height of the resulting tree will be `~N`, where `N` is the length of the array. By inserting the numbers in random order, there is a high chance the height of the tree will be about `logN`. In other words, the randomness facilitates the distribution of the elements.

A problem the `Treap` data structure solves is to avoid the height of a *Binary Search Tree* getting too tall.

