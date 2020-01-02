#include<stdio.h>
#include<stdlib.h>

typedef struct node_t
{
   int data;				 //Queue node (node_t): data value (int) and a pointer to the next element(ok).
   node_t *next; 	//Queue structure (queue_t): front and rear pointers and count of queue items.
};

typedef struct queue_t
{
  		int count=0;
		  node*rear;
		  node*front;		 
};
void push(queue_t * q,int data)


int enqueue(queue_t*, node_t*)	//Enqueues the node to the back of the queue.
enqueue(queue_t *,int data){
	if
}

node_t* dequeue(queue_t*)		// Dequeues the front node from the queue, returns error if queue is empty.
 int reset_queue(queue_t*)		// Resets the queue to initial conditions.
 int empty_queue(queue_t*)		// Returns true if queue is empty
//Allocate a queue and reset it.
// Enqueue 3 values to this queue as obtained from the keyboard.
//Dequeue these values and display.
