#ifndef NODE_H
#define NODE_H

class Node {
public:
  char song[100];
  Node *next;
  Node *prev;

  Node(const char *songName = "");
};

#endif
