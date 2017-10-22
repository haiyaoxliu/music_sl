#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "list.h"
#include "music_lib.h"

void insert_song(struct song_node *p, struct song_node *table[26]) {
  int i = p->artist[0]-'a';
  if(!table[i]) {
    table[i] = p;
    return;
  }

  struct song_node *tmp = create(table[i]->name,table[i]->artist);
  tmp->next = table[i]->next;
  table[i] = insert_order(tmp, p);

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

void print_artist(struct song_node *p, struct song_node *table[26]) {
  struct song_node *tmp = find_artist(p,table);
  while(tmp && !strcmp(p->artist,tmp->artist)) {
    printf(" %s |",tmp->name);
    tmp = tmp -> next;
  }
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
  printf("%c:\t",c);
  print_list(table[c-'a']);
  return;
}

void print_library(struct song_node *table[26]) {
  int i;

  for (i = 0; i < 26; i++) {
    char l = 'a'+i;
    printf("%c:\t",l);
    print_list(table[i]);
  }
}

void delete_song(struct song_node *p, struct song_node *table[26]) {
  table[(p -> artist)[0] - 'a'] = delete_song_list(table[(p -> artist)[0]-'a'], p);
}

struct song_node * delete_song_list(struct song_node *h, struct song_node *p) {
  struct song_node *to_ret = h;
  struct song_node *tmp = h;

  if (!h) {
    return h;
  }
  if(!song_comp(h,p)) {
    h = NULL;
    return to_ret->next;
  }
  while(h && song_comp(h,p)) {
    tmp = h;
    h = h->next;
  }
  /*while (strcmp(p -> artist, h -> artist) > 0) {
    tmp = h;
    h = h -> next;
  }
  while (!(strcmp(p -> artist, h -> artist)) && strcmp(p -> name, h -> name) > 0) {
    tmp = h;
    h = h -> next;
  }
  if (!strcmp(p -> artist, h -> artist) && !strcmp(p -> name, h -> name)) {
    tmp -> next = h -> next;
    h = ;
  }*/
  if(h) {
    tmp -> next = h -> next;
    free(h);//return to_ret;
  }
  return to_ret;
}

void delete_all(struct song_node *table[26]) {
  int i;
  for (i = 0; i < 26; i++) {
    if(table[i]) {
      table[i] = free_list(table[i]);
    }
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
  for(i = 0; i < j/2 + rand()%(j/2); i++) { 
    print_rand(table[count[rand() % j]]);
  }
}

void print_rand(struct song_node *p) {
  int i = 0;
  struct song_node *j = p;
  while (p) {
    i++;
    p = p -> next;
  }
  int count = rand() % i;
  while(count > 0) {
    j = j -> next;
    count--;
  }
  printf("%s, %s |\n", j -> artist, j -> name);
}

/*int main() {
  return 0;
  }*/
