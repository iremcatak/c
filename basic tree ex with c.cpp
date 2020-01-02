#include<stdio.h> 
#include<stdlib.h> 
   
struct node 
{ 
    int key; 
    struct node *left, *right; 
}; 
   
// A utility function to create a new BST node 
struct node *newNode(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
   
// A utility function to do inorder traversal of BST 
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d \n", root->key); 
        inorder(root->right); 
    } 
} 
   bool ifNodeExists(struct Node* node, int key) 
{ 
    if (node == NULL) 
        return false; 
  
    if (node -> data == key) 
        return true; 
  
    /* then recur on left sutree */
    bool res1 = ifNodeExists(node->left, key); 
  
    if(res1) return true; // node found, no need to look further 
  
    /* node is not found in left, so recur on right subtree */
    bool res2 = ifNodeExists(node->right, key); 
  
    return res2; 
} 
/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key);    
  
    /* return the (unchanged) node pointer */
    return node; 
} 
  int findMax(struct Node* root) 
{ 
    // Base case 
    if (root == NULL) 
      return INT_MIN; 
  
    // Return maximum of 3 values: 
    // 1) Root's data 2) Max in Left Subtree 
    // 3) Max in right subtree 
    int res = root->data; 
    int lres = findMax(root->left); 
    int rres = findMax(root->right); 
    if (lres > res) 
      res = lres; 
    if (rres > res) 
      res = rres; 
    return res; 
} 
 void printMinMax(Node* root) 
{ 
      
    if (root == NULL)  
    { 
        cout << "Tree is empty"; 
        return; 
    } 
      
    Node* current = root; 
      
    Node* pre; 
      
    // Max variable for storing maximum value     
    int max_value = INT_MIN;  
      
    // Min variable for storing minimum value     
    int min_value = INT_MAX;  
      
      
    while (current != NULL) 
    {  
        // If left child does nor exists 
        if (current->left == NULL) 
        {  
            max_value = max(max_value, current->key); 
            min_value = min(min_value, current->key); 
              
            current = current->right;  
        }  
        else 
        {  
    
            // Find the inorder predecessor of current  
            pre = current->left;  
            while (pre->right != NULL && pre->right !=  
                                                 current)  
                pre = pre->right;  
    
            // Make current as the right child  
            // of its inorder predecessor  
            if (pre->right == NULL) 
            {  
                pre->right = current;  
                current = current->left;  
            }  
    
            // Revert the changes made in the 'if' part to  
            // restore the original tree i.e., fix the  
            // right child of predecessor 
            else 
            {  
                pre->right = NULL;  
                  
                max_value = max(max_value, current->key); 
                min_value = min(min_value, current->key); 
              
                current = current->right;  
            } // End of if condition pre->right == NULL 
              
        } // End of if condition current->left == NULL 
          
    } // End of while  
      
    // Finally print max and min value 
    cout << "Max Value is : " << max_value << endl; 
    cout << "Min Value is : " << min_value << endl; 
} 
  
// Driver Program to test above functions 
int main() 
{ 
    /* Let us create following BST 
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 */
    struct node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
   
    // print inoder traversal of the BST 
    inorder(root); 
   printf ("Maximum element is %d \n", findMax(root)); 
    return 0; 
} 
