#include <stdio.h>
#include <stdlib.h>



#define CAPACITY 3 



typedef struct node_t 
{
    int data;
    struct node_t * next;
} queue_t;    

unsigned int size = 0;


int enqueue(queue_t ** rear, queue_t ** front, int data);
int dequeue(queue_t ** front);
int getRear(queue_t * rear);
int getFront(queue_t * front);
int isEmpty();
int isFull();


int main()
{
    int a, data;
    queue_t*rear, *front;

    rear  = NULL;
    front = NULL;

   
    while (1)
    {
        printf("------------------------------------------\n");
        printf("  QUEUE LINKED LIST IMPLEMENTATION PROGRAM\n");
        printf("------------------------------------------\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Size\n");
        printf("4. Get Rear\n");
        printf("5. Get Front\n");
        printf("0. Exit\n");
        printf("------------------------------------------\n");
        printf("Select an option: ");

        scanf("%d", &a);

      
        switch (a)
        {
            case 1:
                printf("\nEnter data to enqueue: ");
                scanf("%d", &data);

                if (enqueue(&rear, &front, data))
                    printf("Element added to queue.");
                else
                    printf("Queue is full.");

                break;

            case 2:
                data = dequeue(&front);

              
                if (data == INT_MIN)
                    printf("Queue is empty.");
                else
                    printf("Data => %d", data);

                break;

            case 3: 

              
                if (isEmpty())
                    printf("Queue is empty.");
                else 
                    printf("Queue size => %d", size);

                break;

            case 4: 
                data = getRear(rear);

                if (data == INT_MIN)
                    printf("Queue is empty.");
                else 
                    printf("Rear => %d", data);

                break;

            case 5: 

                data = getFront(front);

                if (data == INT_MIN)
                    printf("Queue is empty.");
                else 
                    printf("Front => %d", data);

                break;

            case 0:
                printf("Exiting from program.\n");
                exit(0);
        
            default:
                printf("Invalid choice, please enter a number between (0-5).");
                break;
        }

        printf("\n\n");
    }
}




int enqueue(queue_t ** rear, queue_t ** front, int data)
{
    queue_t * newNode = NULL;

   
    if (isFull())
    {
        return 0;
    }

   
    newNode = (queue_t *) malloc (sizeof(queue_t));

   
    newNode->data = data;

    newNode->next = NULL;

   
    if ( (*rear) )
    {
        (*rear)->next = newNode;
    }
    

    *rear = newNode;

   
    if ( !( *front) )
    {
        *front = *rear;
    }

   
    size++;

    return 1;
}


int dequeue(queue_t ** front)
{
    queue_t *toDequeue = NULL;
    int data = INT_MIN;


    if (isEmpty())
    {
        return INT_MIN;
    }

   
    toDequeue = *front;
    data = toDequeue->data;

    *front = (*front)->next;

  
    size--;

    
    free(toDequeue);

    return data;
}



int getRear(queue_t * rear)
{
    
    return (isEmpty())
            ? INT_MIN
            : rear->data;
}



int getFront(queue_t * front)
{
    return (isEmpty())
            ? INT_MIN
            : front->data;
}



int isEmpty()
{
    return (size <= 0);
}



int isFull()
{
    return (size > CAPACITY);
}

