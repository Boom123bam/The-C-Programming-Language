#include <stdio.h>
#include <stdlib.h>

// store array of nums in a binary tree

struct node {
  int num;
  struct node *left;
  struct node *right;
  int count;
};

struct node *getNewNode(int num);
struct node *addNum(int num, struct node *target);
void printTree(struct node *root);

int main() {
  int nums[] = {3457, 975, 3457, 3457, 34, 2, 34, 31, 7,
                8,    456, 2,    35,   1,  8, 7,  35, 6236};
  struct node root_node = {
      .num = nums[0],
      .left = NULL,
      .right = NULL,
  };

  for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
    addNum(nums[i], &root_node);
  }
  printTree(&root_node);

  return 0;
}

struct node *getNewNode(int num) {
  // return malloc(sizeof(struct node));
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->num = num;
  newNode->left = 0;
  newNode->right = 0;
  newNode->count = 1;
  return newNode;
}

struct node *addNum(int num, struct node *target) {
  if (num < target->num) {
    // left
    if (!target->left) {
      // add to left
      struct node *newNode = getNewNode(num);
      target->left = newNode;
      return newNode;
    }
    return addNum(num, target->left);
  } else if (num > target->num) {
    // right
    if (!target->right) {
      // add to right
      struct node *newNode = getNewNode(num);
      target->right = newNode;
      return newNode;
    }
    return addNum(num, target->right);
  } else {
    // is equal
    // increase count
    target->count++;
    return target;
  }
}

void printTree(struct node *currentNode) {
  if (currentNode->left)
    printTree(currentNode->left);
  printf("%d x %d\n", currentNode->num, currentNode->count);
  if (currentNode->right)
    printTree(currentNode->right);
  return;
}
