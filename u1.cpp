#include <stdio.h>
#include <stdlib.h>


/* Structure of a node */
struct node {
    int data;          // Data
    struct node *next; // Address
}*node_t;

struct list { 
    struct node_t *front, *rear; 
    int count;
}list_t; 

if(rear == NULL)
{
     front = rear = new struct node_t();
     rear->data = key;
}
else
{
     struct node_t* temp = new struct node_t();
     temp->data = key;
     rear->next = temp;
     rear = temp;
}
if(front->next == NULL)
{
     delete front;
     front = rear = NULL;
     return;
}
struct node_t* temp = front;
front = temp->next;
delete temp;

void createList(int n);
int countNodes();
void displayList();


int main()
{
    int n, total;

    /*
     * Create a singly linked list of n nodes
     */
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);

    printf("\nData in the list \n");
    displayList();

    /* Count number of nodes in list */
    total = countNodes();

    printf("\nTotal number of nodes = %d\n", total);

    return 0;
}


/*
 * Create a list of n nodes
 */
void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

   node_t = (struct node *)malloc(sizeof(struct node));

    /*
     * If unable to allocate memory for head node
     */
    if(node_t == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        /*
         * Read data of node from the user
         */
        printf("Enter the data of node 1: ");
        scanf("%d", &data);

        node_t->data = data; // Link data field with data
       node_t->next = NULL; // Link address field to NULL

        temp = head;

        /*
         * Create n nodes and adds to linked list
         */
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            /* If memory is not allocated for newNode */
            if(newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);

                newNode->data = data; // Link the data field of newNode with data
                newNode->next = NULL; // Link the address field of newNode with NULL

                temp->next = newNode; // Link previous node i.e. temp to the newNode
                temp = temp->next;
            }
        }

        printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}


/*
 * Counts total number of nodes in the list
 */
int countNodes()
{
    int count = 0;
    struct node *temp;

    temp = node_t;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}


/*
 * Displays the entire list
 */
void displayList()
{
    struct node *temp;

    /*
     * If the list is empty i.e. head = NULL
     */
    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = node_t;
        while(temp != NULL)
        {
            printf("Data = %d\n", temp->data); // Print data of current node
            temp = temp->next;                 // Move to next node 
        }
    }
}
