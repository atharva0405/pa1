#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *next;
};

int insert(int x, struct node* table[]) {
  int key = abs(x) % 10000;
  struct node *newnode = (struct node*)malloc(sizeof(struct node));
  struct node *ptr = (struct node*)malloc(sizeof(struct node));
  ptr = table[key];
  //int coll = 0;
  if (table[key] != NULL) {
    while(ptr != NULL) {
      while (table[key]->next != NULL) {
        table[key] = table[key]->next;
      }
      newnode->data = x;
      newnode->next = table[key];
      table[key] = newnode;
      ptr = ptr->next;

    }
    return 1;
  }
  else {
    newnode->data = x;
    newnode->next = table[key];
    table[key] = newnode;
  }
  return 0;
}

int search(int x, struct node* table[]) {
  int key = abs(x) % 10000;
  struct node *ptr = (struct node*)malloc(sizeof(struct node)); //pointer to traverse
  ptr = table[key];
  //int hits = 0;
  while (ptr != NULL) {
    if (x == ptr->data) {
      //hits++;
      //printf("%d\n", ptr->data );
      return 1;
    }
    ptr = ptr->next;
  }
  return 0;
}

int main(int argc, char *argv[]) {
  struct node* table[10000];
  int i;
  for(i = 0; i < 10000; i++) {
    table[i] = NULL;
  }
  FILE *fptr;
  char *filename = argv[1];
  fptr = fopen(filename, "r");
  char comm;
  int value;
  int coll = 0;
  int hits = 0;
  while (!feof(fptr)) {
    fscanf(fptr, "%c %d\n", &comm, &value);
    if (comm == 'i') {
      int a = insert(value, table);
      if (a == 1) {
        coll++;
      }
    }
    if (comm == 's') {
      int b = search(value, table);
      if (b == 1) {
        hits++;
      }
    }
  }
  printf("%d\n%d\n", coll, hits);
  return 0;
}
