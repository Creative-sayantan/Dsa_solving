#include <stdio.h>
#include <stdlib.h>
struct node {
  int data;
  struct node* left;
  struct node* right;
};
struct node* createNode(int data) {
  struct node* newNode = (struct node*)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}
void insert(struct node** root, int data) {
  if (*root == NULL) {
    *root = createNode(data);
    return;
  }

  if (data < (*root)->data) {
    insert(&((*root)->left), data);
  }
  else {
    insert(&((*root)->right), data);
  }
}

struct node* search(struct node* root, int data) {
  if (root == NULL || root->data == data) {
    return root;
  }

  if (data < root->data) {
    return search(root->left, data);
  }
  else {
    return search(root->right, data);
  }
}

int main(void) {
  struct node* root = NULL;

  insert(&root, 50);
  insert(&root, 30);
  insert(&root, 20);
  insert(&root, 40);
  insert(&root, 70);
  insert(&root, 60);
  insert(&root, 80);

  int data = 30;
  struct node* result = search(root, data);

  if (result != NULL) {
    printf("Data %d found in the tree\n", data);
  } else {
    printf("Data %d not found in the tree\n", data);
  }

  return 0;
}

