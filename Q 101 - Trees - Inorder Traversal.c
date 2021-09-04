// Question Name :- Q 101 - Trees - Inorder Traversal //

/*
Your task is to implement the following function :

void inorder(TreeNode*)
You will be working with the following structure :

struct TreeNode {
	int x;
    struct TreeNode* L;
    struct TreeNode* R;
}
You may only edit the BODY of the code, leaving the HEAD and the TAIL as it is.

Sample Input 0

7
4 2 1 3 6 7 5
Sample Output 0

1 2 3 4 5 6 7 
*/

// Solution //

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

struct node* insert( struct node* root, int data ) {
        
    if(root == NULL) {
    
        struct node* node = (struct node*)malloc(sizeof(struct node));

        node->data = data;

        node->left = NULL;
        node->right = NULL;
        return node;
      
    } else {
      
        struct node* cur;
        
        if(data <= root->data) {
            cur = insert(root->left, data);
            root->left = cur;
        } else {
            cur = insert(root->right, data);
            root->right = cur;
        }
    
        return root;
    }
}

void inOrder( struct node *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}


int main() {
  
    struct node* root = NULL;
    
    int t;
    int data;

    scanf("%d", &t);

    while(t-- > 0) {
        scanf("%d", &data);
        root = insert(root, data);
    }
  
    inOrder(root);
    return 0;
}