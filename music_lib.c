#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "main.h"
#include "list.c"

struct song_node *table[26];



void insert_song(song_node *p) {
  if (!p) {
    table[(p -> artist)[0]-'a'] = insert_front(table[(p -> artist)[0]-'a'], p);
  }
  else {
    table[(p -> artist)[0]-'a'] = insert_order(table[(p -> artist)[0]-'a'], p);
  }
  return 
}

struct song_node * find(song_node *p) {
  return find_list(table[(p -> artist)[0]-'a'], p);
}

struct song_node * find_list(song_node *h, song_node *p) {
  if (!h) {
    return h;
  }
  while (strcmp(p -> artist, h -> artist) > 0) {
    h = h -> next;
  }
  while (!(strcmp(p -> artist, h -> artist)) && strcmp(p -> name, h -> name) > 0) {
    h = h -> next;
  }
  if (!strcmp(p -> artist, h -> artist) && !strcmp(p -> name, h -> name)) {
    return h;
  }
  else {
    return NULL;
  }
}

struct song_node * find_artist(song_node *p) {
  return find_artist_list(table[(p -> artist)[0]-'a'], p);
}

struct song_node * find_artist_list(song_node h, song_node *p) {
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

void print_letter(char c) {
  print_list(table[c-'a']);
}

void print_library() {
  int i;
  for (i = 0; i < 26; i++) {
    if (table[i]) {
      print_letter('a' + i);
    }
  }
}

struct song_node * delete_song(song_node *p) {
  return table[(p -> artist)[0]-'a'] = delete_song_list(table[(p -> artist)[0]-'a'], p);
}

struct song_node * delete_song_list(song_node *h, song_node *p) {
  song_node *to_ret = h;
  song_node *tmp = h;
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

void delete_all() {
  int i;
  for (i = 0; i < 26; i++) {
    table[i] = free_list(table[i]);
  }
}


void shuffle() {
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
  for (i; i > 0; i--) {
    j = j -> next;
  }
  printf("%s | %s\n", j -> artist, j -> name);
}


int main() {
  return 0;
}
