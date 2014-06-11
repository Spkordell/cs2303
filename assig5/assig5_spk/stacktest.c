#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

typedef struct {
  int x;
  double y;
} Foo; // Just some arbitrary struct


void fillStackWithFoos(Stack* new_stack) {
  Foo* new_foo3; 
  Foo* new_foo4; 
  Foo* new_foo5; 
  Foo* new_foo6; 
  Foo* new_foo7;
  Foo* returned_foo;

  //allocate some foos
  new_foo3 = (Foo *) malloc(sizeof(Foo));
  new_foo4 = (Foo *) malloc(sizeof(Foo));
  new_foo5 = (Foo *) malloc(sizeof(Foo));
  new_foo6 = (Foo *) malloc(sizeof(Foo));
  new_foo7 = (Foo *) malloc(sizeof(Foo));

  //Fill the stack with five foos
  new_foo3->x=1;
  new_foo3->y=1.1;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo3->x, new_foo3->y);
  push(new_stack, (void *) new_foo3);  
  new_foo4->x=2;
  new_foo4->y=2.2;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo4->x, new_foo4->y);
  push(new_stack, (void *) new_foo4); 

  // Peek at the top of the stack
  returned_foo = (Foo *) peek(new_stack);
  printf("Peeked:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
 
  new_foo5->x=3;
  new_foo5->y=3.3;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo5->x, new_foo5->y);
  push(new_stack, (void *) new_foo5); 
  new_foo6->x=4;
  new_foo6->y=4.4;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo6->x, new_foo6->y);

  push(new_stack, (void *) new_foo6);  
  new_foo7->x=5;
  new_foo7->y=5.5;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo7->x, new_foo7->y);
  push(new_stack, (void *) new_foo7);  
}

void popMultipleFoos(Stack* new_stack, int FoosToPop) {
  Foo* returned_foo;
  while (FoosToPop--) {
    returned_foo = (Foo *) pop(new_stack);
    printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  }
}

void freeAllFoos(Stack* new_stack) {
  Foo* returned_foo;
  char FoosToPop = 5;
  fillStackWithFoos(new_stack);
  while (FoosToPop--) {
    returned_foo = (Foo *) pop(new_stack);
    printf("Popped and freed:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
    free(returned_foo);
  }
}

int main() {
  const int max_entries = 5; // size of stack
  Foo* new_foo1;
  Foo* new_foo2; 
  Foo* returned_foo;

  // First, create a stack
  Stack *new_stack = create_stack(max_entries);

  printf("Testing general pushing and popping of data.\n");
  // Allocate a Foo and push it onto the stack.
  new_foo1 = (Foo *) malloc(sizeof(Foo));
  new_foo1->x = 6;
  new_foo1->y = 14.79;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo1->x, new_foo1->y);
  push(new_stack, (void *) new_foo1);

  // Allocate another Foo and push it onto the stack.
  new_foo2 = (Foo *) malloc(sizeof(Foo));
  new_foo2->x = 217;
  new_foo2->y = 3.14159;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo2->x, new_foo2->y);
  push(new_stack, (void *) new_foo2);

  // Peek at the top of the stack
  returned_foo = (Foo *) peek(new_stack);
  printf("Peeked:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);

  // Retrieve the Foos and print them.
  returned_foo = (Foo *) pop(new_stack);
  printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  returned_foo = (Foo *) pop(new_stack);
  printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);

  printf("\nFilling Stack:\n");
  //demonstrate some more foo pushing and popping
  fillStackWithFoos(new_stack);
  printf("Emptying Stack:\n");  
  popMultipleFoos(new_stack,5);

  
  printf("\nAttempting to peak at empty stack:\n");
  if ((returned_foo = (Foo *) peek(new_stack)) == NULL) {
    printf("Failed to Peak\n");
  } else {
    printf("Peeked:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  }
  
  printf("\nAttempting to overfill the stack:\n");
  fillStackWithFoos(new_stack);
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo1->x, new_foo1->y);
  if(push(new_stack, (void *) new_foo1) < 0) {
       printf("Failed to push: x = %5d, y = %10.3f\n", new_foo1->x, new_foo1->y);
       // Peek at the top of the stack
       returned_foo = (Foo *) peek(new_stack);
       printf("Peeked:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  }
  printf("\nAttempting to pop more foos than available.\n");
  popMultipleFoos(new_stack,5);

  if ((returned_foo = (Foo *) pop(new_stack)) == NULL) {
    printf("STACK IS EMPTY - CAN'T POP\n");
  } else {
    printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  }

  // Clean up
  printf("\n");
  freeAllFoos(new_stack);
  delete_stack(new_stack);
  free(new_foo1);
  free(new_foo2);
  printf("Memory Freed\n");
  return 0;
}
