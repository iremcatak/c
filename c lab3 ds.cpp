#include <stdio.h>
#include <stdlib.h>

typedef struct node 
 {
 void* dataPtr;
 struct node* next;
 } node_t; 
 
typedef struct
 {
 node_t* front,rear;
 int count;
 } list_t;
 
 
 struct node_t* newNode(int k) 
{ 
    struct node_t* temp = (struct node_t*)malloc(sizeof(struct node_t)); 
    temp->data = k; 
    temp->next = NULL; 
    return temp; 
} 
//front ve rearý'ý null a eþitle ve count 0 a eþitle

node_t* front = NULL;
node_t*  rear= NULL;
list_t* count=0;

struct node_t* temp;
struct node* start = NULL;
struct node* createNode()
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    return newNode;
}
//Spesifik bir pozisyona eleman ekleyen fonksiyon, belirttiðiniz pozisyonun bir öncesinde bulunan düðümü bulup onun önüne düðümü ekliyor
void addPos(int z, int index)
{
    int counter = 0;
    struct node* anywhere = createNode();
    anywhere->data = z;
    temp = start;
    if(index == 0)
    {
        addFirst(z);
    }
    else
    {
            while(temp != NULL)
            {
                if(counter+1 == index)
                    break;
                temp = temp->next;
                counter++;
            }
            struct node* temp1;
            temp1 = temp->next;
            temp->next = anywhere;
            anywhere->next = temp1;
    }
 
}

//Baðlý listeyi ekrana basan fonksiyon
void printLinked()
{
    if(start == NULL)
    {
        printf("\n Your List is EMPTY");
    }
    else
    {
        temp = start;
        printf("\n********************\n");
        while(temp->next != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d ", temp->data);
        printf("\n");
    }
 
}
 
//Akýllara zarar menü fonksiyonumuz
void menu()
{
    while(1 == 1)
    {
        printf("\n***************************************************");
        printf("\n***************************************************");
       
        printf("\n3- Herhangi bir pozisyona eleman ekle ... ");
      
        printf("\n6- Herhangi bir sayiyi sil ... ");
    
     
        scanf("%d", &choise);
        selection(choise);
    }
 
}
 
//Menüden yapýlan seçimi handle eden fonksiyon
void selection(int choise)
{
    int item, i, index;
    switch(choise)
    {
      
        case 3:
            printf("Hangi sayiyi eklemek istiyorsunuz? ...");
            scanf("%d", &item);
            printf("Hangi indexe yerlestirmek istiyorsunuz? (ilk sayi 0. indexte) ...");
            scanf("%d", &index);
            addPos(item, index);
            printLinked();
            break;
       
        case 6:
            printf("\n Hangi sayiyi silmek istiyorsunuz? ...");
            scanf("%d", &item);
            deleteSpes(item);
            printLinked();
            break;
        
 
    }
}
 
//Main fonksiyonumuz
int main()
{
    menu();
}
