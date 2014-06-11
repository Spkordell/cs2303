#include <stdlib.h>
#include "queue.h"

Queue* create_queue(int max_cells) {
  Queue* new_queue = (Queue*) malloc(sizeof(Queue)); //allocate the queue
  if (new_queue == NULL) return NULL; //error, unable to allocate
  
  //save the details
  new_queue->max_cells = max_cells;
  new_queue->cells_used = 0; //Queue is originally empty

  new_queue->queue_head = (void**) calloc(sizeof(void*), max_cells);
  if (new_queue->queue_head == NULL) {
    free (new_queue); //failed to allocate, free and return error
    return NULL;
  }

  new_queue->queue_tail = new_queue->queue_head;
  return new_queue;
}

int enqueue(Queue* which_queue, void *ptr) {
  if (which_queue->cells_used >= which_queue->max_cells) {
    return -1; //Queue is full
  }

  //enqueu
  *(which_queue->queue_tail) = ptr;
  (which_queue->cells_used)++;

  //wrap around if necessary
  if (*(which_queue->queue_tail) == (which_queue + which_queue->max_cells)) {
    *(which_queue->queue_tail) = which_queue;
  } else {
    (which_queue->queue_tail)++;
  }
}

void* dequeue(Queue *which_queue) {
  if (which_queue->cells_used <= 0) {
    return NULL; //queue is empty
  }

  //check for rollover and dequeue
 (which_queue->cells_used--);
 if (*(which_queue->queue_head) == (which_queue + which_queue->max_cells)) {
   *(which_queue->queue_head) == which_queue;
   return (which_queue + which_queue->max_cells);
 } else {
   return(*((which_queue->queue_head)++));
 }
}


void* front(Queue *which_queue) {
  if (which_queue->cells_used <= 0) {
    return NULL; //queue is empty
  }

  //return head of queue
   return *(which_queue->queue_head);
}

int delete_queue(Queue* which_queue) {
  if (which_queue->cells_used > 0) {
    return -1; //Queue is not empty
  }
  free(which_queue);
  return 1;
}
