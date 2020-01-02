#include<stdlib.h>
#include<stdio.h>

struct b_tree {
int data;
struct b_tree * left, * right ;
};

typedef struct b_tree node;


void insert(node ** tree, int val)
{
    node *temp = NULL;
    if(!(*tree))
    {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}
void print_inorder(node * tree)
{
    if (tree)
    {
        print_inorder(tree->left);
        printf("%d\n",tree->data);
        print_inorder(tree->right);
    }
}

void print_preorder(node * tree)
{
    if (tree)
    {
        printf("%d\n",tree->data);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }

}

void print_postorder(node * tree)
{
    if (tree)
    {
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d\n",tree->data);
    }
}


node* search(node ** tree, int val)
{
    if(!(*tree))
    {
        return NULL;
    }

    if(val < (*tree)->data)
    {
        search(&((*tree)->left), val);
    }
    else if(val > (*tree)->data)
    {
        search(&((*tree)->right), val);
    }
    else if(val == (*tree)->data)
    {
        return *tree;
    }
}
    
   int find_min(node*root)
{
	if(root== NULL)
	printf("tree is mepty\n");

	if (root->left)
	return find_min(root->left);

	else
	printf("\nmin value:%d\n",root->data);
	return 0;
}

int find_max(node*root){
	if(root==NULL)
	printf("\ntree is empty\n");
	
	if(root->right)
	return find_max(root->right);
	else
	
	printf("\nmax value:%d\n", root->data);
	return 0;
}
 int main()
{
   
     
    node *root;
    node *tmp;
    

    root = NULL;
    insert(&root, 25);
    insert(&root, 6);
    insert(&root, 15);
    insert(&root, 3 );
    insert(&root, 15);
    insert(&root, 39);
    insert(&root, 2);


    printf("inorder display\n\n");
    print_inorder(root);
   
    printf("\npreorder display\n\n");
    print_preorder(root);

    printf("\npostorder display\n\n");
    print_postorder(root);
 
    tmp = search(&root, 3);
    if (tmp)
    {
        printf("\nSearched node=%d\n", tmp->data);
    }
    else
    {
        printf("\nData Not found in tree.\n");
    }

   find_max(root);
   
   find_min(root);
   
   }
