/** @file treetest.c
 */

#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

int main() {
  
  Tnode* root = add_tnode(NULL,"Hydrogen");
  add_tnode(root,"Helium");
  add_tnode(root,"Lithium");
  add_tnode(root,"Beryllium");
  add_tnode(root,"Boron");
  add_tnode(root,"Carbon");
  add_tnode(root,"Nitrogen");
  add_tnode(root,"Oxygen");
  add_tnode(root,"Florine");
  add_tnode(root,"Neon");

  //Sodium is intentially added twice to test repeating data
  add_tnode(root,"Sodium");
  add_tnode(root,"Sodium");
  add_tnode(root,"Magnesium");
  add_tnode(root,"Aluminium");
  add_tnode(root,"Silicon");
  add_tnode(root,"Phosporus");
  add_tnode(root,"Sulfur");
  add_tnode(root,"Cholorine");
  add_tnode(root,"Argon");
  add_tnode(root,"Potassium");
  add_tnode(root,"Scandium");

  printf("\n");
  traverseDescending(root);
  printf("\n");

  freeTree(root);
  return 0;
}
