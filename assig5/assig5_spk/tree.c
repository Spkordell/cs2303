/**@file tree.c
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.h"


/**Add a Tnode to a Tnode on left child if value is alphabetically before or equal or right child if alphabetically after.
 * @param current_tnode The node to attach the new node to.If NULL, will allocate a new Node and return it
 * @param value The value to place in the new node.
 * @return Pointer to the Tnode or NULL if operation failed
 * @author Steven Kordell
*/
Tnode *add_tnode(Tnode* current_tnode, char* value) {
  if (current_tnode == NULL) {
    //Allocate a new tree node
    Tnode* new_node = (Tnode*) malloc(sizeof(Tnode));
    //initialize the left and right child nodes
    if (new_node != NULL) {
      new_node->leftChild = NULL;
      new_node->rightChild = NULL;
      //Save the value
      new_node->value = strdup(value);
      // new_node->value = value;
      //return the new node
      return new_node;
    } else {
      return NULL;
    }
  }
  if(strcmp(convertToUpper(value),convertToUpper(current_tnode->value)) <= 0) { //if aphabetically less or equal
    current_tnode->leftChild = add_tnode(current_tnode->leftChild,value);
  } else {
    current_tnode->rightChild = add_tnode(current_tnode->rightChild,value); //if alphabetically after
  }
  return current_tnode;
}

/** Recursively traverses the tree "in order" but in reverse, that is, visit the right node, then the current node, then the left node
 * @param current_tnode The tnode to visit recursively
 * @author Steven Kordell
 */
void traverseDescending(Tnode* current_tnode) {
  if (current_tnode != NULL) { //if we're not at the end of the tree
    traverseDescending(current_tnode->rightChild); //visit the right node
    printf("%s\n",current_tnode->value); //visit the current node
    traverseDescending(current_tnode->leftChild); //visit the left node
  }
}

/** Converts a string to all upper case characters
 * @param str Pointer to the c-style string to convert
 * @return Pointer to the returned string
 * @author Steven Kordell
 */
char* convertToUpper(char *str){
    char *newstr, *p;
    p = newstr = strdup(str); //amke a cpy of the string
    while(*p++=toupper(*p)); //iterate over it, uppercasing the characters
    return newstr; //return the resulting string
}

/** Frees all the nodes in a tree as well as their contents
 * @param current_tnode The first node to free, all the subnodes will be freed
 * @author Steven Kordell
*/
void freeTree(Tnode* current_tnode) {
  if (current_tnode != NULL) { //Are we at the end of the branch?
    freeTree(current_tnode->leftChild); //free the left child
    freeTree(current_tnode->rightChild);//free the right child
    free(current_tnode->value);//free the string of this node
    free(current_tnode); //free this node
  }
}
