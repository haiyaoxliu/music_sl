#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "list.h"
#include "music_lib.h"

void insert_song(struct song_node *p, struct song_node *table[26]) {
  
  printf("in func\n\n\n\n\n");
  //if (!p) {
  //table[(p -> artist)[0]-'a'] = insert_front(table[(p -> artist)[0]-'a'], p);
  //}
  //else {
  int i = p->artist[0]-'a';
  printf("index defined\n\n\n\n\n\n\n");
  table[i] = insert_order(table[i], table[i]);//create(p->name,p->artist));//malloc(sizeof(struct song_node));
  printf("value set\n\n\n\n\n\n\n");
    //}
  return;
}

struct song_node * find(struct song_node *p, struct song_node *table[26]) {
  return find_list(table[(p -> artist)[0]-'a'], p);
}

struct song_node * find_list(struct song_node *h, struct song_node *p) {
  //printf("0");
  //struct song_node * h = l;

  if (!h) {
    //printf("1");
    return h;
  }
  while (strcmp(p -> artist, h -> artist) > 0) {
    h = h -> next;
  }
  while (!(strcmp(p -> artist, h -> artist)) && strcmp(p -> name, h -> name) > 0) {
    h = h -> next;
  }
  //printf("2");

  if (!strcmp(p -> artist, h -> artist) && !strcmp(p -> name, h -> name)) {
    //printf("3");
    return h;
  }
  else {
    //printf("4");
    return NULL;
  }
}

struct song_node * find_artist(struct song_node *p, struct song_node *table[26]) {
  return find_artist_list(table[(p -> artist)[0]-'a'], p);
}

struct song_node * find_artist_list(struct song_node *h, struct song_node *p) {
  //struct song_node * h = l;
  if (!h) {
    return h;
  }
  while (strcmp(p -> artist, h -> artist) > 0) {
    h = h -> next;
  }
  if (!strcmp(p -> artist, h -> artist)) {
    return h;
  }
  else {
    return NULL;
  }
}

void print_letter(char c, struct song_node *table[26]) {
  char l = 97+c;
  printf("%c:\t",l);
  print_list(table[c-'a']);
}

void print_library(struct song_node *table[26]) {
  //printf("\np\n");
  int i;
  //printf("\np\n");

  for (i = 0; i < 26; i++) {
    //printf("p");
    printf("%p\n",table[i]);
    if (table[i]) {
    struct song_node *tmp = table[i];
    printf("%i:\t",i);
    //printf("p");

    //char letter = (char)i;
    //printf("p");
    //print_letter(letter,table[i]);
      printf("\n");
      }
      else {
      char l = 'a'+i;
      //printf();
      printf("%c\n",l);
      }
  }
}

struct song_node * delete_song(struct song_node *p, struct song_node *table[26]) {
  return delete_song_list(table[(p -> artist)[0]-'a'], p);
}

struct song_node * delete_song_list(struct song_node *h, struct song_node *p) {
  struct song_node *to_ret = h;
  struct song_node *tmp = h;

  if (!h) {
    return h;
  }
  while (strcmp(p -> artist, h -> artist) > 0) {
    tmp = h;
    h = h -> next;
  }
  while (!(strcmp(p -> artist, h -> artist)) && strcmp(p -> name, h -> name) > 0) {
    tmp = h;
    h = h -> next;
  }
  if (!strcmp(p -> artist, h -> artist) && !strcmp(p -> name, h -> name)) {
    tmp -> next = h -> next;
    free(h);
  }
  return to_ret;
}

void delete_all(struct song_node *table[26]) {
  int i;
  for (i = 0; i < 26; i++) {
    table[i] = free_list(table[i]);
  }
}

void shuffle(struct song_node *table[26]) {
  srand(time(NULL));
  int i;
  int j = 0;
  int count[26];
  for (i = 0; i < 26; i++) {
    if (table[i]) {
      count[j] = i;
      j++;
    }
  }
  print_rand(table[count[rand() % j]]);
}

void print_rand(struct song_node *p) {
  int i = 0;
  struct song_node *j = p;
  while (p) {
    i++;
  }
  while(i > 0) {
    j = j -> next;
    i--;
  }
  printf("%s | %s\n", j -> artist, j -> name);
}

/*int main() {
  return 0;
  }*/
