#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *front = NULL;
//struct node *ptr = (struct node*)malloc(sizeof(struct node));

int add(int y){
  struct node * newnode = (struct node*)malloc(sizeof(struct node));
  newnode->data = y;
  if (front == NULL) {
    newnode->next = front;
    front = newnode;
    return 1;
  }
  else {
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr = front;
    struct node *prev = (struct node*)malloc(sizeof(struct node));
    while (ptr != NULL) {
      if (ptr->data < y) {
        prev = ptr;
        ptr = ptr->next;
      }
      else {
        if (ptr == front) {
          newnode->next = front;
          front = newnode;
          return 1;
          break;
        }
        else {
          prev->next = newnode;
          newnode->next = ptr;
          return 1;
          break;
        }
      }
      if (ptr == NULL) { //last node in LL
        prev->next = newnode;
        newnode->next = ptr;
        return 1;
      }
    }
  }
  return 0;
}

int delete(int y) {
  struct node *ptr = (struct node*)malloc(sizeof(struct node));
  ptr = front;
  struct node *prev = (struct node*)malloc(sizeof(struct node));
  //printf("hello");
  while (ptr != NULL) {
    if (ptr->data == y) {
      if (ptr == front) {
        front = front->next;
      }
      else{
        prev->next = ptr->next;
      }
      return 1;
    }
    prev = front;
    ptr = ptr->next;
  }
  return -1;
}

int main(int argc, char *argv[]) {
  FILE *fptr;
  char *filename = argv[1];
  fptr = fopen(filename, "r");
  if (fptr == NULL) {
    printf("error\n");
  }

  char comm; //command
  int value; //value to insert or delete
  int count = 0;
  while(!feof(fptr)) {
    fscanf(fptr, "%c %d\n", &comm, &value);
    if(comm == 'i') {
      int x = add(value);
      if (x == 1) {
        count++;
      }
    }
    if(comm == 'd'){
      int z = delete(value);
      if (z == 1) {
        count--;
      }
    }
  }
  fclose(fptr);
  printf("%d\n", count);
  if (count > 0) {
    if (front == NULL) {
      printf("0\n");
    }
    else {
      struct node *ptr = (struct node*)malloc(sizeof(struct node));
      int before = 0;
      ptr = front;
      while (ptr != NULL) {
        if (ptr->data != before) {
          printf("%d\t", ptr->data);
          before = ptr->data;
        }
        ptr = ptr->next;
      }
      printf("\n");
    }
  }
  return 0;
}
