#ifndef QUEUE_H
#define QUEUE_H


/** Struct to define a queue; each entry can hold a pointer to anything.
 */
struct queue {
  //things are added to the tail of the queue and removed from the head
  void** queue_head; // Points to the first element of the queue
  void** queue_tail;  // Points to the  next free cell;
  int max_cells; // Maximum number of entries in the queue
  int cells_used; // Currently used number of cells
};

typedef struct queue Queue;

// Function prototypes


/** Create a queue by allocating a Queue structure, initializing it,
 *  and allocating memory to hold the queue entries.
 * @param max_cells Maximum entries in the queue
 * @return Pointer to newly-allocated queue structure, NULL if error.
 */
Queue* create_queue(int max_cells);


/** Adds a pointer onto the tail of the queue.
 * @param which_queue Pointer to queue you want to enqueue to.
 * @param ptr Pointer to be enqueued.
 * @return 0 if successful, -1 if not.
 */
int enqueue(Queue *which_queue, void *ptr);

/** Removes and returns the pointer at the head of the queue
 * @param which_queue Pointer to queue you want to dequeue
 * @return head of the queue, NULL if queue is empty.
 */
void* dequeue(Queue *which_queue);

/** Returns the element at the head of the queue without removing it
 * @param which_queue The queue to front
 * @return the pointer at the front of the queue
 */
void* front(Queue *which_queue);


/** Deallocates the queue if it is empty
 * @param which_queue The queue to delete
 * @returns, -1 if the delete fails, 1 otherwise
 */
int delete_queue(Queue* which_queue);


#endif
