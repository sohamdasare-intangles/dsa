// Implementation of Binary Search Tree (BST)

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"


int main(){

    struct node *root = NULL;

    root = bst_insert(root, 10);
    root = bst_insert(root, 4);
    root = bst_insert(root, 17);
    root = bst_insert(root, 6);
    root = bst_insert(root, 2);
    root = bst_insert(root, 21);
    root = bst_insert(root, 11);

    printf("Inorder\n");
    inorder(root);
    printf("\n\n");

    /*

    printf("Minimum key in BST : %d\n", bst_min(root));
    printf("Maximum key in BST : %d\n", bst_max(root));
    printf("Height of the BST : %d\n", bst_height(root));

    (bst_search_val(root, 11)) 
                        ? printf("KEY FOUND!\n")
                        : printf("Key not found.\n");
    printf("\n\n");

    (bst_search(root, 22))
                        ? printf("Node Found!\n")
                        : printf("Node not found\n");

    printf("\n\n");

    */

    root = bst_delete(root, 17);

    printf("Inorder\n");
    inorder(root);
    printf("\n\n");


    return 0;
}



// BST Functions


struct node* init_node(struct node *temp, int val){

    temp->key = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}



struct node* bst_insert(struct node *root, int ikey){

    if (NULL == root){

        struct node *root = (struct node*)malloc(sizeof(struct node));
        root = init_node(root, ikey);

        return root; 
    }

    if (ikey == root->key) {
        printf("bst_inserting duplicate key not allowed!!\n");
    }
    else if (ikey < root->key) {
        root->left = bst_insert(root->left, ikey);
    }
    else if (ikey > root->key) {
        root->right = bst_insert(root->right, ikey);
    }

    return root;
}


struct node* bst_delete(struct node *root, int dkey) { 

    if(NULL == root) return root;

    // There are three possible cases: 
    // 1. dkey has 2 child
    // 2. dkey has no child (leaf node)
    // 3. dkey has 1 child

    int case_no = 0;
    struct node *par, *ptr;
    int child_pos = 0; // To find if child is in  left or right position
    
    ptr = root;
    par = NULL;

    while(ptr) {

        // Found the key
        if (dkey == ptr->key){
            break;
        }

        par = ptr;

        if (dkey < ptr->key) {
            ptr = ptr->left;
            child_pos = LEFT;
        }
        else{
            ptr = ptr->right;
            child_pos = RIGHT;
        }

    }

    // At this point, ptr -> node to be deleted, par -> the parent node, child_pos -> side of ptr in respect to par

    if(NULL == ptr) {
        printf("To delete node not found\n");
        return root;
    }

    // Two child
    if (NULL != ptr->right && NULL != ptr->left) {
        case_no = TWO_CHILD;
    }
    // No child
    else if (NULL == ptr->right && NULL == ptr->left) {
        case_no = NO_CHILD;
    }
    // One child
    else {
        case_no = ONE_CHILD;
    }

    
    switch (case_no) {

        case TWO_CHILD:
            {   
                // Find inorder successor and its parent
                struct node *succ, *parsucc;
                parsucc = ptr;
                succ = ptr->right;
                child_pos = RIGHT; // Initial case (if to delete node has leaf nodes)

                while(NULL != succ->left) {
                    parsucc = succ;
                    succ = succ->left;
                    child_pos = LEFT;
                }

                // Copy the data
                ptr->key = succ->key;

                // Visualise this
                if (NULL != succ->right) {
                    parsucc->left = succ->right;
                }
                
                // Initial case, didn't enter while
                if(child_pos == RIGHT) {
                    parsucc->right = NULL;
                }
                
                free(succ);
                return root;
            }
            break;

        case NO_CHILD:
            {   
                // Root to be deleted
                if (NULL == par) {
                    root = NULL;
                }
                else if (LEFT == child_pos) {
                    par->left = NULL;
                }
                else {
                    par->right = NULL;
                }

                free(ptr);
                return root;

            }
            break;

        case ONE_CHILD:
            {
                struct node *child;
                if(ptr->left) {
                    child = ptr->left;
                }
                else {
                    child = ptr->right;
                }
                
                // Root to be deleted
                if (NULL == par) {
                    root = child;
                }

                if (par->left) {
                    par->left = child;
                }
                else {
                    par->right = child;
                }

                free(ptr);
                return root;

            }
            break;

        default:
            break;
    }

}


struct node* bst_search(struct node *root, int skey){
    
    if(NULL == root) return root;

    if(skey == root->key) {
        return root;
    }
    else if (skey < root->key) {
        return bst_search(root->left, skey);
    }
    else if (skey > root->key) {
        return bst_search(root->right, skey);
    }
}



int bst_search_val(struct node *root, int skey) {

    if(NULL == root) return 0;

    if (skey == root->key) {
        return 1;
    }
    else if (skey < root->key) {
        return bst_search_val(root->left, skey);
    }
    else if (skey > root->key) {
        return bst_search_val(root->right, skey);
    }
}



int bst_min(struct node *root) {

    if(NULL == root) return 0;

    if (NULL == root->left) {
        return root->key;
    }

    bst_min(root->left);
}



int bst_max(struct node *root) {

    if(NULL == root) return 0;

    if (NULL == root->right)  return root->key;
    

    bst_max(root->right);
    
}

int bst_height(struct node *root) {

    if(NULL == root) return 0;

    int left_height = 0;
    int right_height = 0;

    left_height = bst_height(root->left);
    right_height = bst_height(root->right);

    if(left_height > right_height){
        return left_height + 1;
    } 
    else {
        return right_height + 1;
    }

}



// Traversal functions 


void inorder(struct node *root){

    if(NULL == root) return;

    inorder(root->left);
    printf("%d  ", root->key);
    inorder(root->right);

}

void preorder(struct node *root){

    if(NULL == root) return;

    printf("%d  ", root->key);
    preorder(root->left);
    preorder(root->right);
    
}

void postorder(struct node *root){

    if(NULL == root) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d  ", root->key);

}
