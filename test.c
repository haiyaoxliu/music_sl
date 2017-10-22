#include <stdio.h>
#include <string.h>
#include "list.h"
#include "music_lib.h"

int main() {
  struct song_node *mlib[26];
  struct song_node *l;

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

  printf("inserted\n\n\n");

  insert_song(create("paris","magic man"),mlib);
  printf("inserted\n\n\n");


  insert_song(create("big coat","wiretree"),mlib);
  printf("inserted\n\n\n");


  insert_song(create("breezeblocks","alt-j"),mlib);
  insert_song(create("float on","modest mouse"),mlib);
  insert_song(create("idfc","blackbear"),mlib);
  insert_song(create("out of mind","magic man"),mlib);
  insert_song(create("come together","beatles"),mlib);
  insert_song(create("ain't no rest for the wicked","cage the elephant"),mlib);
  insert_song(create("kangaroo court","capital cities"),mlib);
  insert_song(create("redbone","childish gambino"),mlib);
  insert_song(create("good news","ocean park standoff"),mlib);
  insert_song(create("billie jean","michael jackson"),mlib);
  insert_song(create("all i want","kodaline"),mlib);
  insert_song(create("hotel california","eagles"),mlib);
  insert_song(create("yesterday","beatles"),mlib);

  printf("inserted\n\n\n");
  
  print_library(mlib);


  return 0;
}
