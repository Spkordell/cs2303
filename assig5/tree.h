/** @file tree.h
 */

#ifndef TREE_H
#define TREE_H


struct _Tnode {
  char* value;  //data is a pointer to a C-style string
  struct _Tnode* leftChild; //pointer to the left child
  struct _Tnode* rightChild;//pointer to the Right child
};

typedef struct _Tnode Tnode;


Tnode *add_tnode(Tnode* current_tnode, char* value);
void traverseDescending(Tnode* current_tnode);
char* convertToUpper(char *str);
void freeTree(Tnode* current_tnode);

#endif
