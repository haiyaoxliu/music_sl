#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void print_list(struct song_node *p) {
  while (p != NULL) {
    printf("%s | %s -> ", p -> artist, p -> name);
    p = p -> next;
  }
  printf("NULL\n");
}

struct song_node * insert_front(struct song_node *p, struct song_node *n) { //char n[], char a[]) {
  n -> next = p;
  return n;
}

int song_comp(struct song_node *p1, struct song_node *p2) {
  if (!strcmp(p1 -> artist, p2 -> artist)) {
    return strcmp(p1 -> name, p2 -> name);
  }
  return strcmp(p1 -> artist, p2 -> artist);
}

struct song_node * create(char n[], char a[]) {
  struct song_node* new = (struct song_node*)malloc(sizeof(struct song_node));
  strcpy(new -> name, n);
  strcpy(new -> artist, a);
  new -> next = NULL;
  return new;
}

struct song_node * insert_order(struct song_node *p, struct song_node *n) { //char n[], char a[]) {
  //printf("func");
  //struct song_node *new = (struct song_node*)malloc(sizeof(struct song_node));
  struct song_node *tmp;
  struct song_node *to_ret = p;
  //printf("assignments");
  //strcpy(new -> name, n);
  //strcpy(new -> artist, a);
  //printf("new created");
  while (p && song_comp(n, p) >= 0) {
    //printf("loop");
    tmp = p;
    p = p -> next;
  }
  tmp -> next = n;
  n -> next = p;
  return to_ret;
}

struct song_node * free_list(struct song_node *p) {
  while (p) {
    struct song_node * q = p;
    free(p);
    p = q -> next;
  }
  return NULL;
}

int main() {
  /*struct song_node * table[26];
  struct song_node * a = (struct song_node*)malloc(sizeof(struct song_node));
  //a->name = "HEAD";
  //a->artist = "HEAD";
  print_list(a);

  printf("what\n");
  a = insert_order(a,"test","");
  printf("what\n");

  a = insert_front(a,"feel good inc.","gorillaz");
  print_list(a);
  a = insert_front(a,"zzz","naptime");
  print_list(a);

  char w[] = "www";

  //problem with using too many double quot decl is we run out of memory.

  printf("what\n");
  a = insert_order(a,w,w);
  printf("what\n");

  print_list(a);
  a = insert_order(a,"goat","alex lu");
  print_list(a);*/
  return 0;
}
