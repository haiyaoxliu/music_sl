#include <stdio.h>
#include <string.h>
#include "list.h"
#include "music_lib.h"

int main() {
  struct song_node *mlib[26];
  struct song_node *l;

  int i;
  for (i = 0; i < 26; i++) {
    mlib[i] = NULL;
  }

  printf("===========================================\nLIST TESTS\n\nprint (empty):\n");
  print_list(l);

  l = insert_front(l,create("paris","magic man"));
  l = insert_front(l,create("big coat","wiretree"));
  l = insert_front(l,create("breezeblocks","alt-j"));
  l = insert_front(l,create("float on","modest mouse"));
  l = insert_front(l,create("idfc","blackbear"));
  l = insert_front(l,create("blackbird","beatles"));

  printf("\n\ninsert_front:\n");
  print_list(l);

  l = free_list(l);

  printf("\n\nfree_list:\n");
  print_list(l);

  l = insert_order(l,create("alibi","clans"));
  l = insert_order(l,create("let me down easy","sheppard"));
  l = insert_order(l,create("loud","coucheron"));
  l = insert_order(l,create("geronimo","sheppard"));
  l = insert_order(l,create("clint eastwood","gorillaz"));
  l = insert_order(l,create("lemon tree","fools garden"));
  
  printf("\n\ninsert_order:\n");
  print_list(l);

  printf("\n\nfind_list:\n");

  struct song_node *s = create("alibi","clans");
  struct song_node *t = find_list(l,s);
  printf("find alibi,clans:\t%p\t%s\t%s\n",s,s->name,s->artist);

  //s = free_list(s);
  //t = free_list(t);
  /*
  struct song_node *p = create("bbbbb","bbbbb");
  struct song_node *q = find_list(l,p);
  printf("find bbbbb,bbbbb:\t%p",q);
  */

  //print_list(l);

  printf("\n\nfind_artist_list:\n");

  struct song_node *p = create("geronimo","sheppard");
  struct song_node *q = find_list(l,p);
  printf("find sheppard:\t%p\t%s\t%s\n\n",q,q->name,q->artist);

  l = free_list(l);
  
  printf("===========================================\nLIB TESTS\n\nprint (empty):\n");
  print_library(mlib);
  
  insert_song(create("paris","magic man"),mlib);
  //print_list(mlib['m'-97]);

  insert_song(create("big coat","wiretree"),mlib);
  //print_list(mlib['w'-97]);

  insert_song(create("breezeblocks","alt-j"),mlib);
  //print_list(mlib['a'-97]);

  insert_song(create("float on","modest mouse"),mlib);
  //print_list(mlib['m'-97]);

  insert_song(create("idfc","blackbear"),mlib);
  //print_list(mlib['b'-97]);

  insert_song(create("out of mind","magic man"),mlib);
  //print_list(mlib['m'-97]);
  
  insert_song(create("come together","beatles"),mlib);
  //print_list(mlib['b'-97]);

  insert_song(create("ain't no rest for the wicked","cage the elephant"),mlib);
  //print_list(mlib['c'-97]);

  insert_song(create("kangaroo court","capital cities"),mlib);
  //print_list(mlib['c'-97]);

  insert_song(create("redbone","childish gambino"),mlib);
  //print_list(mlib['c'-97]);

  insert_song(create("good news","ocean park standoff"),mlib);
  //print_list(mlib['o'-97]);

  insert_song(create("billie jean","michael jackson"),mlib);
  //print_list(mlib['m'-97]);

  insert_song(create("all i want","kodaline"),mlib);
  //print_list(mlib['k'-97]);

  insert_song(create("hotel california","eagles"),mlib);
  //print_list(mlib['e'-97]);

  insert_song(create("yesterday","beatles"),mlib);
  //print_list(mlib['b'-97]);

  //for(i = 0; i < 26; i++) {
  //print_list(mlib[i]);
  //}


  printf("\n\ninsert song:\n\n");
  print_library(mlib);

  printf("\n\nfind:\n\n");
  printf("yesterday,beatles:\t%p", find(create("yesterday","beatles"),mlib));
  printf("\nblackbird,beatles:\t%p", find(create("blackbird","beatles"),mlib));

  printf("\n\nfind_artist:\n\n");
  printf("beatles:\t%p",find_artist(create("","beatles"),mlib));
  printf("\nnigel stanford:\t%p",find_artist(create("","nigel stanford"),mlib));

  printf("\n\nprint_artist:\n\n");
  printf("beatles:\t");
  print_artist(create("","beatles"),mlib);
  printf("\nnigel stanford:\t");
  print_artist(create("","nigel stanford"),mlib);

  printf("\n\nprint_letter:\n\n");
  print_letter('b',mlib);

  printf("\n\nshuffle:\n\n");
  shuffle(mlib);

  printf("\n\ndelete:\n\n");
  printf("redbone, good news, big coat:\n");
  delete_song(create("redbone","childish gambino"), mlib);
  delete_song(create("good news","ocean park standoff"), mlib);
  delete_song(create("big coat","wiretree"), mlib);
  print_library(mlib);

  printf("\n\ndelete_all:\n\n");
  delete_all(mlib);
  print_library(mlib);

  //printf("\n\ninsert song:\n\n");
  //print_library(mlib);
  

  return 0;
}
