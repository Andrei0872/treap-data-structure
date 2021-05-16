#include <iostream>

#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

ifstream f("abce.in");
ofstream g("abce.out");

const int NUMBER_LIMIT = 2000005;

struct Node {
  int value, priority;
  Node* right;
  Node* left;
  Node* parent;

  Node (int v, int p): value(v), priority(p) {};
};

bool isLeaf (Node*& node) {
  return !node->left && !node->right;
}

Node* findPlaceInBST (Node*& root, Node*& newNode, Node*& parent) {
  if (!root) {
    return newNode;
  }
  
  parent = NULL;
  if (newNode->value < root->value) {
    parent = root;
    root->left = findPlaceInBST(root->left, newNode, parent);
  }

  // Doing another check on purpose so that no duplicate value are allowed
  if (newNode->value > root->value) {
    parent = root;
    root->right = findPlaceInBST(root->right, newNode, parent);
  }

  return root;
}

void rotateLeft (Node*& root, Node*& node) {
  Node* nodeParent = node->parent;
  Node* rightChild = node->right;
  Node* initialNode = node;

  if (nodeParent) {
    if (nodeParent->right == node) {
      node->parent->right = rightChild;
    } else {
      node->parent->left = rightChild;
    }
  }

  node->right = rightChild->left;
  if (node->right) {
    node->right->parent = node;
  }

  rightChild->left = node;
  node->parent = rightChild;

  rightChild->parent = nodeParent;

  if (initialNode == root) {
    root = rightChild;
    root->parent = NULL;
  }
}

void rotateRight (Node*& root, Node*& node) {
  Node* nodeParent = node->parent;
  Node* leftChild = node->left;
  Node* initialNode = node;

  if (nodeParent) {
    if (nodeParent->right == node) {
      node->parent->right = leftChild;
    }

    node->parent->left = leftChild;
  }

  node->left = leftChild->right;
  if (node->left) {
    node->left->parent = node;
  }

  leftChild->right = node;
  node->parent = leftChild;

  leftChild->parent = nodeParent;

  if (initialNode == root) {
    root = leftChild;
    root->parent = NULL;
  }
}

void goUpwards (Node*& root, Node*& node) {
  while (node && node->parent && node->parent->priority > node->priority) {
    bool isLeftChild = node->parent->left == node;
    if (isLeftChild) {
      rotateRight(root, node->parent);
    } else {
      rotateLeft(root, node->parent);
    }

    node = node->parent;
  }

  if (node && node->parent == NULL) {
    root = node;
  }
}

void insertNode (Node*& root, int value) {
  Node *newNode = new Node(value, rand() % NUMBER_LIMIT);

  if (root == NULL) {
    root = newNode;

    return;
  }

  Node* parent = NULL;
  findPlaceInBST(root, newNode, parent);
  newNode->parent = parent;

  if (!parent) {
    return;
  }

  goUpwards(root, newNode);
}

Node* findNode (Node*& root, int value) {
  if (!root) {
    return NULL;
  }
  
  if (root->value == value) {
    return root;
  }

  Node* leftResult = findNode(root->left, value);
  return leftResult != NULL ? leftResult : findNode(root->right, value);
}

void goDownwards (Node*& root, Node*& node) {
  while (!isLeaf(node)) {
    if (!node->left) {
      rotateLeft(root, node);
    } else if (!node->right) {
      rotateRight(root, node);
    } else if (node->left->priority < node->right->priority) {
      rotateRight(root, node);
    } else {
      rotateLeft(root, node);
    }
  }
}

void safelyDetachNode (Node*& node) {
  if (node->parent->left == node) {
    node->parent->left = NULL;
  } else {
    node->parent->right = NULL;
  }

  node->parent = NULL;

  delete node;
}

void deleteNode (Node*& root, int value) {
  Node* nodeToDelete = findNode(root, value);

  if (!nodeToDelete) {
    return;
  }

  goDownwards(root, nodeToDelete);
  safelyDetachNode(nodeToDelete);
}

void checkIfValueExists (Node*& root, int value) {
  Node* foundNode = findNode(root, value);

  g << (foundNode ? 1 : 0) << '\n';
}


Node* getPredecessorOf (Node*& root, int value, Node* crtPredecessor = NULL) {
  if (!root) {
    return crtPredecessor;
  }
  
  int diff = value - root->value;
  if (diff >= 0) {
    crtPredecessor = root;
  }

  return getPredecessorOf(
    value > root->value ? root->right : root->left,
    value,
    crtPredecessor
  );
}


int main () {
  srand(time(NULL));

  Node *root = NULL;

  int nrInstructions;
  int instructionType;
  int X, Y;

  f >> nrInstructions;

  for (int i = 0; i < nrInstructions; i++) {
    f >> instructionType >> X;

    switch (instructionType) {
      case 1: {
        insertNode(root, X);

        break;
      }
      
      case 2: {
        // Delete X
        deleteNode(root, X);

        break;
      }

      case 3: {
        // Search for X
        checkIfValueExists(root, X);

        break;
      }

      case 4: {
        // Predecessor of X
        Node* pred = getPredecessorOf(root, X);
        g << pred->value << '\n';
        
        break;
      }

      case 5: {
        // Successor of X

        break;
      }

      case 6: {
        // Print values between X and Y

        f >> Y;
        break;
      }
    }
  }

  return 0;
}