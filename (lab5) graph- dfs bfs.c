#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 7
//vertex=düðüm
typedef struct vertex {
int label; // 0,1,2,3,4,5,6
int visited;// 0:=unvisited , 1:=visited
}vertex_t;

//stack variables
int stack[MAX]; 
int top = -1;
int label;
int queue[MAX];
int rear = -1;
int front = 0;
int queueItemCount = 0;
//array of vertices
vertex_t* listVertices[MAX];
//adjacency matrix=komþuluk matrisi
int adjMatrix[MAX][MAX];
//vertex count
int vertexCount = 0;
//stack functions

void push(int item) { 
stack[++top] = item; 
} 

int pop() { 
return stack[top--]; 
} 

int peek() {
return stack[top];
}

bool isStackEmpty() {
return (top == -1);
}

//queue functions
void insert(int data) {
queue[++rear] = data;
queueItemCount++;
}

int removeData() {
queueItemCount--;
return queue[front++]; 
}

bool isQueueEmpty() {
return queueItemCount == 0;
}

//graph functions
//add vertex to the vertex list
void addVertex (int label) {
vertex_t* newVertex;
newVertex = (vertex_t*)malloc(sizeof(vertex_t));
newVertex->label = label; 
newVertex->visited = 0; 
listVertices[vertexCount++] = newVertex;
}
//edge=hat
//add edge to edge array
void addEdge(int start,int end) {
adjMatrix[start][end] = 1;
adjMatrix[end][start] = 1;
}

//display the vertex
void displayVertex(int vertexIndex) {
printf("%d ",listVertices[vertexIndex]->label);
} 

//get the adjacent unvisited vertex
int getAdjUnvisitedVertex(int vertexIndex) {
int i;

for(i = 0; i < vertexCount; i++) {

if(adjMatrix[vertexIndex][i] == 1 && listVertices[i]->visited == 0) {
return i;
}
}
return -1;
}

void depthFirstSearch() {
int i;

//mark first node as visited
listVertices[0]->visited = 1;
//display the vertex
displayVertex(0); 
//push vertex index in stack
push(0);

while(!isStackEmpty()) {
//get the unvisited vertex of vertex which is at top of the stack
int unvisitedVertex = getAdjUnvisitedVertex(peek());

//no adjacent vertex found
if(unvisitedVertex == -1) 
{
pop();
} 

else 
{
listVertices[unvisitedVertex]->visited = 1;
displayVertex(unvisitedVertex);
push(unvisitedVertex);
}
}

//stack is empty, search is complete, reset the visited flag 
for(i = 0;i < vertexCount;i++) {
listVertices[i]->visited = 0;
}
}

void breadthFirstSearch() 

{

int i;
//mark first node as visited
listVertices[2]->visited = 1;
//display the vertex
displayVertex(2); 
//insert vertex index in queue
insert(2);
int unvisitedVertex;

while(!isQueueEmpty()) {
//get the unvisited vertex of vertex which is at front of the queue
int tempVertex = removeData(); 
//no adjacent vertex found

while((unvisitedVertex = getAdjUnvisitedVertex(tempVertex)) != -1) { 
listVertices[unvisitedVertex]->visited = true;
displayVertex(unvisitedVertex);
insert(unvisitedVertex); 
}
} 
//queue is empty, search is complete, reset the visited flag 
for(i = 0;i<vertexCount;i++) {
listVertices[i]->visited = false;
} 
}



int main() {
int i, j;
for(i = 0; i < MAX; i++) // set adjacency 
{
for(j = 0; j < MAX; j++) // matrix to 0
adjMatrix[i][j] = 0;
}
addVertex(0); // 0
addVertex(1); // 1
addVertex(2); // 2
addVertex(3); // 3
addVertex(4); // 4
addVertex(5); // 5
addVertex(6); // 6

addEdge(0, 1); // 0 - 1
addEdge(0, 6); // 0 - 6
addEdge(1, 2); // 1 - 2
addEdge(1, 5); // 1 - 5
addEdge(1, 6); // 1 - 6
addEdge(2, 3); // 2 - 3
addEdge(2, 4); // 2 - 4
addEdge(2, 5); // 2 - 5
addEdge(3, 4); // 3 - 4
addEdge(4, 5); // 4 - 5
addEdge(5, 6); // 5 - 6


printf("Depth First Search: ");
depthFirstSearch(); 

printf("\n");
printf("\nBreadth First Search: ");

breadthFirstSearch();

printf("\n");

for(i = 0; i < MAX; i++) // set adjacency 
{
printf("\n");
for(j = 0; j < MAX; j++) // matrix to 0 
printf("%d ", adjMatrix[i][j]);
}
return 0; 
}
