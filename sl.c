#include <stdlib.h>
#include <stdio.h>

typedef struct operations operations;
typedef struct song_node song_node, *sn;

struct song_node {
  char name[256];
  char artist[256];
  song_node *next;
  operations *ops;
};

struct operations {
  sn (*insertf)(song_node *);
  sn (*insert)(song_node *);
  sn (*print)(song_node *);
  sn (*finds)(song_node *, char *[], char *[]);
  sn (*finda)(song_node *, char *[]);
  sn (*random)(song_node *);
  sn (*remove)(song_node *, char *[], char *[]);
  sn (*free)(song_node *);
};

sn insertf()
