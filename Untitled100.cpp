#include <stdio.h>
#include <stdlib.h>
 
//////**********www.algoritmauzmani.com***********\\\\\
 
//sadece men� i�in global de�i�ken
int choise;
 
//d���mlerimizi tutaca��m�z struct yap�s�
struct node{
    int data;
    struct node *next;
};
 
//Ba�lang�� d���m�(start) ve ge�ici de�i�ken (temp) olu�turuyoruz
struct node* start = NULL;
struct node* temp;
 
//d���m olu�turan fonksiyon, geriye d���m (node) return ediyor
struct node* createNode()
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    return newNode;
}
 
//Ba�l� liste sonuna eleman ekleyen fonksiyon
void addLast(int x)
{
    struct node* element = createNode();
    element->data = x;
    element->next = NULL;
 
    //E�er ba�l� liste zaten bo�sa ilk d���m� ekliyoruz
    if(start == NULL)
    {
        start = element;
    }
    else
    {
        //a�a��daki kodlar traverse yap�p d���m�n sonunu buluyor ve yeni d���m� ekliyor
        temp = start;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = element;
    }
 
}
 
//Ba�l� listenin ba��na eleman ekleyen fonksiyon
void addFirst(int y)
{
    struct node* element = createNode();
    element->data = y;
    temp = start;
    element->next = temp;
    start = element;
}
 
//Spesifik bir pozisyona eleman ekleyen fonksiyon, belirtti�iniz pozisyonun bir �ncesinde bulunan d���m� bulup onun �n�ne d���m� ekliyor
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
 
//Ba�l� liste sonundan eleman silen fonksiyon.
void deleteLast()
{
    if(start == NULL)
    {
        printf("\n Your List is EMPTY");
    }
    else
    {
        temp = start;
        if(start->next == NULL)
        {
            free(start);
            start = NULL;
        }
        else
        {
            while(temp->next->next != NULL)
            {
                temp = temp->next;
            }
            struct node* cukubik = temp->next;
            free(cukubik);
            temp->next = NULL;
        }
 
 
    }
 
 
}
 
//Ba�l� listenin ba��ndan eleman silen fonksiyon
void deleteFirst()
{
    if(start != NULL)
    {
        if(start->next != NULL)
        {
            struct node* temp2 = start;
            start = start->next;
            free(temp2);
        }
        else
        {
            free(start);
            start = NULL;
        }
    }
    else
    {
        printf("\nThere is no item to be deleted, Please add item...");
    }
 
 
 
}
 
//Belirtti�iniz say�y� silen fonksiyon
void deleteSpes(int t)
{
    if(start->data == t)
    {
        deleteFirst();
    }
    else
    {
        temp = start;
        while(temp->next->data != t)
        {
            temp = temp->next;
        }
        struct node*temp1 = temp->next->next;
        struct node* temp2 = temp;
        free(temp->next);
        temp2->next = temp1;
    }
 
}
 
//Ba�l� listeyi ters �eviren fonksiyon
void reverseLinked()
{
    struct node* prevNode = NULL;
    struct node* nextNode;
    temp = start;
    while(temp != NULL)
    {
        nextNode = temp->next;
        temp->next = prevNode;
        prevNode = temp;
        temp = nextNode;
    }
    start = prevNode;
}
 
//Ba�l� listeyi ekrana basan fonksiyon
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
 
//Ak�llara zarar men� fonksiyonumuz
void menu()
{
    while(1 == 1)
    {
        printf("\n********* www.algoritmauzmani.com Farkiyla*********");
        printf("\n***************************************************");
        printf("\n***************************************************");
        printf("\n1- Bagli listenin sonuna eleman ekle ... ");
        printf("\n2- Bagli listenin ba$ina eleman ekle ... ");
        printf("\n3- Herhangi bir pozisyona eleman ekle ... ");
        printf("\n4- Bagli Liste sonundaki elemani sil ... ");
        printf("\n5- Bagli Liste ba$indaki elemani sil ... ");
        printf("\n6- Herhangi bir sayiyi sil ... ");
        printf("\n7- Bagli listeyi ters cevir ... ");
        printf("\n Secimini yap, Algoritma Uzmanini Sev ... ");
        scanf("%d", &choise);
        void selection(int choise);
    }
 
}
 
//Men�den yap�lan se�imi handle eden fonksiyon
void selection(int choise)
{
    int item, i, index;
    switch(choise)
    {
        case 1:
 
            printf("\n Kac Tane Sayi Ekleyeceksiniz? ... ");
            scanf("%d", &item);
            for(i = 0; i < item; i++)
            {
                printf("\n Lutfen %d. sayiyi ekleyin... ", i+1);
                scanf("%d", &choise);
                addLast(choise);
                printLinked();
            }
            break;
        case 2:
            printf("En Ba$a eklemen istediginiz sayiyi girin? ... ");
            scanf("%d", &item);
            addFirst(item);
            printLinked();
            break;
        case 3:
            printf("Hangi sayiyi eklemek istiyorsunuz? ...");
            scanf("%d", &item);
            printf("Hangi indexe yerlestirmek istiyorsunuz? (ilk sayi 0. indexte) ...");
            scanf("%d", &index);
            addPos(item, index);
            printLinked();
            break;
        case 4:
            deleteLast();
            printLinked();
            break;
        case 5:
            deleteFirst();
            printLinked();
            break;
        case 6:
            printf("\n Hangi sayiyi silmek istiyorsunuz? ...");
            scanf("%d", &item);
            deleteSpes(item);
            printLinked();
            break;
        case 7:
            reverseLinked();
            printLinked();
 
    }
}
 
//Main fonksiyonumuz
int main()
{
    menu();
}
