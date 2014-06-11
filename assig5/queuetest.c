#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

typedef struct {
  int x;
  double y;
} Foo; // Just some arbitrary struct

void foo_enqueue(Queue* which_queue, Foo* ptr) {
  printf("Adding (%d, %f) to queue...",ptr->x,ptr->y);
  if (enqueue(which_queue,ptr) == -1) {
    printf("FAILED! Queue is full.\n");
  } else {
    printf("SUCCESS!\n");
  }
}

void foo_dequeue(Queue* which_queue) {
  Foo* returned_foo;
  printf("Retrieving data from queue...");
  if ((returned_foo = dequeue(which_queue)) == NULL) {
    printf("FAILED! Queue is Empty.\n");
  } else {
    printf("SUCCESS! Value is (%d, %f)\n",returned_foo->x,returned_foo->y);
  }
}

void foo_front(Queue* which_queue) {
  Foo* returned_foo;
  printf("Peaking at the front of the Queue...");
  if ((returned_foo = front(which_queue)) == NULL) {
    printf("FAILED! Queue is Empty.\n");
  } else {
    printf("SUCCESS! Value is (%d, %f)\n",returned_foo->x,returned_foo->y);
  }
}

int main() {
  const int max_entries = 5; // size of Queue
  Foo* new_foo1;
  Foo* new_foo2; 
  Foo* new_foo3;
  Foo* new_foo4; 
  Foo* new_foo5; 
  Foo* new_foo6; 

  //allocate some foos
  new_foo1 = (Foo *) malloc(sizeof(Foo));
  new_foo2 = (Foo *) malloc(sizeof(Foo));
  new_foo3 = (Foo *) malloc(sizeof(Foo));
  new_foo4 = (Foo *) malloc(sizeof(Foo));
  new_foo5 = (Foo *) malloc(sizeof(Foo));
  new_foo6 = (Foo *) malloc(sizeof(Foo));

  //assign them some values
  new_foo1->x=1;
  new_foo1->y=1.1;
  new_foo2->x=2;
  new_foo2->y=2.2;
  new_foo3->x=3;
  new_foo3->y=3.3;
  new_foo4->x=4;
  new_foo4->y=4.4;
  new_foo5->x=5;
  new_foo5->y=5.5;
  new_foo6->x=6;
  new_foo6->y=6.6;  

  //create a Queue
   Queue* new_queue = create_queue(max_entries);

  
   printf("\n----Playing with the Queue----\n");
   foo_enqueue(new_queue,new_foo1);
   foo_enqueue(new_queue,new_foo2); 
   foo_dequeue(new_queue);
   foo_front(new_queue);
   foo_enqueue(new_queue,new_foo3);
   foo_dequeue(new_queue);
   foo_enqueue(new_queue,new_foo4); 
   foo_dequeue(new_queue);
   foo_dequeue(new_queue);

   printf("\n----Front an empty Queue----\n");   
   foo_front(new_queue);

   printf("\n----Filling Queue----\n");
   foo_enqueue(new_queue,new_foo1);
   foo_enqueue(new_queue,new_foo2);
   foo_enqueue(new_queue,new_foo3);
   foo_enqueue(new_queue,new_foo4);
   foo_enqueue(new_queue,new_foo5);

   printf("\n----Emptying Queue----\n");
   foo_dequeue(new_queue);
   foo_dequeue(new_queue);
   foo_dequeue(new_queue);
   foo_dequeue(new_queue);
   foo_dequeue(new_queue);

   printf("\n----Over Filling Queue----\n");
   foo_enqueue(new_queue,new_foo1);
   foo_enqueue(new_queue,new_foo2);
   foo_enqueue(new_queue,new_foo3);
   foo_enqueue(new_queue,new_foo4);
   foo_enqueue(new_queue,new_foo5);  
   foo_enqueue(new_queue,new_foo6);

   printf("\n----Under Emptying Queue----\n");
   foo_dequeue(new_queue);
   foo_dequeue(new_queue);
   foo_dequeue(new_queue);
   foo_dequeue(new_queue);
   foo_dequeue(new_queue);
   foo_dequeue(new_queue);

  printf("\n----Playing with the Queue More ----\n");
   foo_enqueue(new_queue,new_foo6);
   foo_enqueue(new_queue,new_foo5); 
   foo_enqueue(new_queue,new_foo4); 
   foo_dequeue(new_queue);
   foo_enqueue(new_queue,new_foo3);
   foo_dequeue(new_queue);
   foo_enqueue(new_queue,new_foo2); 
   foo_dequeue(new_queue);
   foo_dequeue(new_queue);
   foo_dequeue(new_queue);

   printf("\nFreeing memory..");
   free(new_foo1);
   free(new_foo2);
   free(new_foo3);
   free(new_foo4);
   free(new_foo5);
   free(new_foo6);
   
   if(delete_queue(new_queue) == 1) {
     printf("SUCCESS!\n");
   } else {
     printf("FAILED!\n");
   }
   return 0;
}
