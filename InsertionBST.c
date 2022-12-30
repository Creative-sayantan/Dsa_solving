#include <stdio.h>
#include <stdlib.h>
struct node {
  int data;
  struct node *left;
  struct node *right;
};
struct node* createNode(int data) {
  struct node* newNode = (struct node*)malloc(sizeof(struct node));

  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}
struct node* insert(struct node* root, int data) {
  if (root == NULL) return createNode(data);

  if (data < root->data)
    root->left = insert(root->left, data);
  else if (data > root->data)
    root->right = insert(root->right, data);

  return root;
}

int main() {
  struct node* root = NULL;

  // Insert some data into the tree
  root = insert(root, 50);
  root = insert(root, 30);
  root = insert(root, 20);
  root = insert(root, 40);
  root = insert(root, 70);
  root = insert(root, 60);
  root = insert(root, 80);

  return 0;
}
