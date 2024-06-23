#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *next;
};


struct node* create_node(int val); 

void print_ll(struct node *head);
struct node* add_at_beg(struct node *head, int val);
struct node* add_at_end(struct node *head, int val);



int main(){

    struct node *head, *fir, *sec, *end;

    head = (struct node*)malloc(sizeof(struct node));
    fir = (struct node*)malloc(sizeof(struct node));
    sec = (struct node*)malloc(sizeof(struct node));
    end = (struct node*)malloc(sizeof(struct node));


    head->val = 5;
    head->next = fir;
    fir->val = 10;
    fir->next = sec;
    sec->val = 15;
    sec->next = end;
    end->val = 20;
    end->next = NULL;

    head = add_at_beg(head, 0);
    head = add_at_end(head, 25);

    print_ll(head);
    

    return 0;
}


// Linked list functions


// This func creates a node with a val and next=NULL, returns the pointer to the struct

struct node* create_node(int val){

    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->next = NULL;
    temp->val = val;

    return temp;
}


	

void print_ll(struct node *head){

    struct node *trav = head;

    while(trav){
        printf("%d->",trav->val);
        trav = trav->next;
    }

    if(NULL == trav){
        printf("NULL\n");
    }
    
}


struct node* add_at_beg(struct node *head, int val){

    struct node *temp = create_node(val);
    temp->next = head;

    return temp;
}


struct node* add_at_end(struct node *head, int val){

    struct node* temp = create_node(val);
    temp->next = NULL;

    if(NULL == head){
        
        head = temp;

    } else{

        struct node *trav = head;

        while(NULL != trav->next){
            trav = trav->next;
        }

        trav->next = temp;

    }

    return head;
}