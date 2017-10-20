#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song_node {
  char name[256];
  char artist[256];
  struct song_node *next;
};

void print_list(struct song_node *);

struct song_node * insert_front(struct song_node *, char[], char[]);

struct song_node * free_list(struct song_node *);

int main() {
  struct song_node * table[26];
  return 0;
}

void print_list(struct song_node* p) {
  while (p != NULL) {
    printf("%s | %s -> ", p -> artist, p -> name);
    p = p -> next;
  }
  printf("NULL\n");
}

struct song_node * insert_front(struct song_node *p, char n[], char a[]) {
  struct song_node* new = (struct song_node*)malloc(sizeof(struct song_node));
  strcpy(new -> name, n);
  strcpy(new -> artist, a);
  new -> next = p;
  return new;
}

int song_comp(struct song_node *p1, struct song_node *p2) {
  if (!strcmp(p1 -> artist, p2 -> artist)) {
    return strcmp(p1 -> name, p2 -> name);
  }
  return strcmp(p1 -> artist, p2 -> artist);
}


struct song_node * insert_order(struct song_node *p, char n[], char a[]) {
  struct song_node *new = (struct song_node*)malloc(sizeof(struct song_node));
  struct song_node *tmp;
  struct song_node *to_ret = p;
  strcpy(new -> name, n);
  strcpy(new -> artist, a);
  while (p && song_comp(new, p) >= 0) {
    tmp = p;
    p = p -> next;
  }
  tmp -> next = new;
  new -> next = p;
  return to_ret;
}


struct song_node * free_list(struct song_node *p) {
  while (p) {
    free(p);
    p = p -> next;
  }
  return NULL;
}

