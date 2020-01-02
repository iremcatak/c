
/*COME205 Data Structures
Lab3 : Linked List Operations

Due Date : 17.12.2019, Lab finish time
1. Objective : To designsingle linked list operations.
2. Procedure: In this assignment you will design and implement the following:
i. List Structure : the following data structures are needed:
? List node (node_t): data value (int) and a pointer to the next element.
? List structure (list_t): front and rear pointers and count of list items.
ii. Operations on list structure :
? node_t* retrieve(list_t* lp, int pos): Retrieves the node at position pos,
returns error if list is empty.
? insert(list_t* lp, int pos, node_t node): Inserts the node at position pos
to the list.
? Ýnt reset_queue(queue_t*): Resets the list to initial conditions.
? Ýnt empty_queue(queue_t*): Returns true if list is empty.
3. Test
? Allocate a list and reset it.
? Insert 4 values to this list as obtained from the keyboard.
? Retrieve the second value and display.
? Find the sum of all data in this list (Exam question)
Grade : Correctness: 10 pts
 Completeness : 10 pts */


#include <stdio.h>
#include <stdlib.h>

int count,dataValue,position,i;
  

typedef struct node
{
  int dataValue;
  struct node * next;
}node_t; //node structure defined

typedef struct list
{
  node_t *front;
  node_t *rear;
  int count;
}list_t; //list structure defined

list_t* lp;  // myListPointer;

node_t* produceNode ();
list_t* produceList ();
node_t* retrieveData (list_t* listPointer, int position);
int insert (list_t *listPointer, int position, node_t *node);
int reset_list (list_t * listPointer);
int isListEmpty (list_t *listPointer);
int displayList (list_t *listPointer);

int main(void)
{
  count = dataValue = position = i = 0;
  
  lp = produceList();
  reset_list(lp);
  

  while(i != 9)
  {
    printf("\n\nLIST OPERATIONS : \n");
    printf("0 to RESET the list\n");
    printf("1 to INSERT a data value at the entered position \n");
    printf("2 to RETREIVE data from the entered position \n");
    printf("3 to check the EMPTINESS of the list \n");
    printf("4 to DISPLAY the list \n");
    printf("9 to EXIT \n\n");
    scanf("%d" , &i);
    switch(i)
    {
      case 0:
        printf("\n");
        reset_list(lp);
        break;
      case 1:
        printf("\nPlease Enter an integer to INSERT your new DATA:  ");
        scanf("%d" , &dataValue);
        printf("\nPlease Enter a position in the list for your new DATA :  ");
        scanf("%d", &position);
        node_t *newNode = produceNode(dataValue);
        insert(lp,position,newNode);
        break;
      case 2:
        printf("\n\nPlease enter the position of the data to be RETRIEVED :");
        scanf("%d", &position);
        retrieveData(lp,position);
        break;
      case 3:
        isListEmpty(lp);               
        break;
      case 4:
        displayList(lp);        
        break;
      case 9:
        printf("\n THANKS FOR VISITING \n   GOOD BYE !!\n\n");
        break;
      default:
        printf("\nwrong move !!!\n\n");
    }//switch
  }//while not 9
  
  return 0;
}//main


node_t* produceNode (int dataValue)
{
  node_t *myNode;
  myNode = (node_t*)malloc(sizeof(node_t));
  myNode->dataValue = dataValue;
  myNode->next=NULL;
  return myNode;
}


list_t* produceList ()
{
  list_t *myList;
  myList = (list_t*)malloc(sizeof(list_t));
  myList->front=NULL;
  myList->rear=NULL;
  myList->count = 0;
  return myList;
}//produceList


node_t* retrieveData (list_t* listPointer, int position)
{
  if (listPointer->front == NULL)//if list is empty
  {
    printf("\nWARNING ! List is EMPTY!\nYou cannot retrieve an element from an empty list!");
  }
  else //List is not empty
  {
    node_t* tempNode =produceNode(0);
   // temp = (node_t*)malloc(sizeof(node_t));
    tempNode = listPointer->front;
    int retreiveCount = 0;
    while (tempNode != NULL )
    {
      retreiveCount++;
      if (position == retreiveCount)
      {
        printf("\nData in position %d is %d ",position, tempNode->dataValue);
        return tempNode;
      }//if
      tempNode = tempNode->next;
    }//while
    printf("\nWARNING ! There are less elements than the wanted position.\nYou have entered %d but in the list there are only %d elements" ,position, count);
  }//else
return NULL;
}//retrievData


int insert (list_t * listPointer, int position, node_t * node)
{
  if (listPointer->front == NULL && position != 1)
  { 
    printf("\nWARNING !! The list is empty so you cannot instert an element other than the 1st position !! ");
  }
  else if (listPointer->front == NULL && position == 1)
  {
    listPointer->front = node;
    listPointer->rear = node;
    listPointer->rear->next = NULL;
    count++;
  }
  else //list is not empty and the position is not one. i.e GENERAL CASE
  {
    node_t* tempNode =produceNode(0);
    tempNode = listPointer->front;
    int insertTempPosition = 1;
    while (tempNode->next != NULL && insertTempPosition != position-1 )//list has more than one element
    {
      insertTempPosition++;
      tempNode = tempNode->next;
    }//while exitted There are two possibilities reached LAST node or reached position
      if ( position == insertTempPosition + 1 )
      {
        node->next = tempNode->next;
        tempNode->next = node;
        printf("\nNew Node with data value %d in position %d has been successfully INSERTED ",node->dataValue, position );
      }// if
      else if (tempNode->next == NULL)
      {
        printf("\nEnd of the list has has been reached.\nThere are only %d elements.\nThere are less number of elements than the desired position", insertTempPosition);
      }

        return insertTempPosition+1;
  }//else GENERAL CASE  
  return 0;
}//insert


int reset_list (list_t * listPointer)
{
  listPointer->front = NULL;
  listPointer->rear = NULL;
  listPointer->count = 0;
  printf("\nList has been just resetted.");
  return 0;
}


int isListEmpty (list_t *listPointer)
{
  if (listPointer->front == NULL)
  { 
    printf("\n\nChecking the emptiness of the list :\nThe list is EMPTY !");
  }
  else
  {
    printf("\n\nChecking the emptiness of the list :\nThe list is NOT EMPTY !");    
  }  
  return 0;
}//isListEmpty


int displayList (list_t *listPointer)
{ 
  int dispSum=0;
  int dispCount = 0;
  printf("\n\n DISPLAYING the LIST ");
  if (listPointer->front == NULL)
  { 
    printf("\n\n There is NOTHING to DISPLAY !! The list is empty.");
  }
  else // list is not empty
  {
    node_t* tempNode = produceNode(0);
    tempNode = listPointer->front;
    while (tempNode != NULL )
    {
      dispCount++;
      dispSum+=tempNode->dataValue;
      printf("  %d  ", tempNode->dataValue );
      tempNode = tempNode->next;
    }//while    
  }//else
  printf("\n\n The number of the nodes in the list is :  %d ", dispCount );
  printf(  "\n The sum of the nodes in the list is    :  %d ", dispSum );  
  return dispSum;
}//dispPlayList

