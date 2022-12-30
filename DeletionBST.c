#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int data;
  struct TreeNode *left;
  struct TreeNode *right;
};

void deleteNode(struct TreeNode** root, int data) {
  if (*root == NULL) {
    return;
  }

  if (data < (*root)->data) {
    deleteNode(&((*root)->left), data);
  }
  else if (data > (*root)->data) {
    deleteNode(&((*root)->right), data);
  }

  else {
    if ((*root)->left == NULL) {
      struct TreeNode* temp = *root;
      *root = (*root)->right;
      free(temp);
    }
    else if ((*root)->right == NULL) {
      struct TreeNode* temp = *root;
      *root = (*root)->left;
      free(temp);
    }
    else {
      struct TreeNode* temp = (*root)->right;
      while (temp->left != NULL) {
        temp = temp->left;
      }
      (*root)->data = temp->data;
      deleteNode(&((*root)->right), temp->data);
    }
  }
}

int main() {

  struct TreeNode* root = NULL;
  root = insertNode(root, 50);
  root = insertNode(root, 30);
  root = insertNode(root, 20);
  root = insertNode(root, 40);
  root = insertNode(root, 70);
  root = insertNode(root, 60);
  root = insertNode(root, 80);

  deleteNode(&root, 40);

  printInorder(root);

  return 0;
}
