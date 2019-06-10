#include <stdio.h>
#include <stdlib.h>

struct BSTNode {
  int data;
  struct BSTNode *left;
  struct BSTNode *right;
};

struct BSTNode *root = NULL;


void insert(int x) {
  struct BSTNode *prev = (struct BSTNode*)malloc(sizeof(struct BSTNode));
  struct BSTNode *ptr = (struct BSTNode*)malloc(sizeof(struct BSTNode));
  struct BSTNode *temp = (struct BSTNode*)malloc(sizeof(struct BSTNode));
  prev = NULL;
  ptr = root;
  //printf("hello2");
  temp->data = x;
  temp->left = NULL;
  temp->right = NULL;


  while (ptr != NULL) {
    prev = ptr;
    if (x == ptr->data) {
      temp = NULL;
      break;
    }
    if (x < ptr->data) {
      ptr = ptr->left;
    }
    else if (x > ptr->data) {
      ptr = ptr->right;
    }
  }
  if (temp != NULL) {
    if (prev == NULL) {
      root = temp;
    }
    else if (x < prev->data) {
      prev->left = temp;
    }
    else if (x > prev->data){
      prev->right = temp;
    }
  }
  //printf("hello3");
}


int main(int argc, char *argv[]) {
  FILE *fptr;
  char *filename = argv[1];
  fptr = fopen(filename, "r");
  char comm;
  int entry;
  int count = 0;
  if (fptr == NULL) {
    printf("error\n");
  }
  //printf("hello1");
  while(!feof(fptr)) {
    fscanf(fptr, "%c %d\n", &comm, &entry);
    count++;
    insert(entry);
  }
  //printf("%d\n",count );
  int i = 0;
  int arr[count+1];
  rewind(fptr);

  while (i < count) {
    while(!feof(fptr)) {
      fscanf(fptr, "%c %d\n", &comm, &entry);
      arr[i] = entry;
      i++;
      //printf("%d\t", arr[1]);
    }
  }


  int temp;
  i = 1;
  int j = 0;
  for (i = 1; i < count; i++) {
    for (j = 0; j < count; j++) {
      if (arr[j] > arr[i]) {
        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
      }
    }
  }
  i = 0;
  j = 1;
  while (i < count) {
    if (arr[i] == arr[j]) {
      i = j;
      j++;
    }
    printf("%d\t", arr[i]);
    i++;
    j++;
  }
  return 0;
}


/*
struct BSTNode *prev = (struct BSTNode*)malloc(sizeof(struct BSTNode));
struct BSTNode *ptr = (struct BSTNode*)malloc(sizeof(struct BSTNode));
prev = NULL;
ptr = root;
//printf("hello2");
while (ptr != NULL) {
  //printf("hello9");
  //printf("%d\n", ptr->left->data );
  while (ptr->left != NULL) {
    prev = ptr;
    ptr = ptr->left;
  }
  //printf("hello4");
  while (ptr->right != NULL) {
    prev = ptr;
    ptr = ptr->right;
  }
  printf("%d\t", ptr->data);
  printf("%d\t", prev->data);

  //printf("hello4");
  //ptr->data = 0;
  //prev->data = 0;
  if (prev->right != NULL) {
    ptr = prev->right;
  }
  else {
    prev = NULL;
    ptr = root;
  }
}
//printf("hello2");
*/
