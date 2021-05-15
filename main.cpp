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

        break;
      }

      case 3: {
        // Search for X

        break;
      }

      case 4: {
        // Predecessor of X
        
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