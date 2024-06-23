/*
    Types or traversal
        1.Inorder
        2.Preorder
        3.Postorder
        4.Levelorder / BFS
*/


#include <stdio.h>
#include <stdlib.h>


struct node* init_node(struct node *t_node, int data);
int height(struct node *root);


void inorder(struct node *root);
void preorder(struct node *root);
void postorder(struct node *root);
void bfs(struct node *root);


struct node
{
    int val;
    struct node* left;
    struct node* right;
};


int main(){

    struct node *root = (struct node*)malloc(sizeof(struct node));
    
    root = init_node(root, 10);

    struct node *node_1 = (struct node*)malloc(sizeof(struct node));
    node_1 = init_node(node_1, 4);

    struct node *node_2 = (struct node*)malloc(sizeof(struct node));
    node_2 = init_node(node_2, 6);

    root->left = node_1;
    root->right = node_2;

    struct node *node_3 = (struct node*)malloc(sizeof(struct node));
    node_3 = init_node(node_3, 3);

    struct node *node_4 = (struct node*)malloc(sizeof(struct node));
    node_4 = init_node(node_4, 5);

    node_1->left = node_3;
    node_1->right = node_4;

    struct node *node_5 = (struct node*)malloc(sizeof(struct node));
    node_5 = init_node(node_5, 1);

    struct node *node_6 = (struct node*)malloc(sizeof(struct node));
    node_6 = init_node(node_6, 8);

    node_2->left = node_5;
    node_2->right = node_6;



    printf("Inorder\n");
    inorder(root);
    printf("\n");

    printf("Preorder\n");
    preorder(root);
    printf("\n");

    printf("Postorder\n");
    postorder(root);
    printf("\n");

    printf("\nHeight of the tree: %d\n\n", height(root));

    return 0;
}


struct node* init_node(struct node *t_node, int data){

    t_node->left = NULL;
    t_node->right = NULL;
    t_node->val = data;

    return t_node;
}


int height(struct node *root){

    int lh = 0;
    int rh = 0;

    if (NULL == root){
        return 0;
    }

    lh = height(root->left);
    rh = height(root->right);

    if(lh > rh){
        return lh + 1;
    }
    else {
        return rh + 1;
    }
}

// Traversal functions 


void inorder(struct node *root){

    if(NULL == root){
        return;
    }

    inorder(root->left);

    printf("%d  ", root->val);

    inorder(root->right);


}

void preorder(struct node *root){

    if(NULL == root){
        return;
    }

    printf("%d  ", root->val);

    preorder(root->left);
    preorder(root->right);
    
}

void postorder(struct node *root){

    if(NULL == root){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    
    printf("%d  ", root->val);

}
