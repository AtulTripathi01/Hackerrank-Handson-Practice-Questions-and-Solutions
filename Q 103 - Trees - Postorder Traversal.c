// Question Name :- Q 103 - Trees - Postorder Traversal //

/*Your task is to implement the following function :

void postorder(TreeNode*)
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

1 3 2 5 7 6 4 

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

void postOrder( struct node *root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
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
  
    postOrder(root);
    return 0;
}