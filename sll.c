#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//define the node
typedef struct node{
    int data;
    struct node *next;
}node;
void display(node *head);
node* create(int n);
node * insert (node *head, int n);
bool find(node *head,int n);
int main(void){

    node * head = NULL;
    // create the head of linked list
    int n;
    printf("Number: ");
    scanf("%i", &n);
    head = create(n);
    int add;
    printf("Do you want add to the linked it. How many?");
    scanf("%i", &add);
     for (int i = 0; i < add ; i++){
         int num;
         printf("Number:- ");
         scanf("%i", &num);
         head = insert(head,num);
     }
    display(head);
    int num_1;
    printf("Search for: ");
    scanf("%i", &num_1);

    find (head, num_1);
}

// function to create the head of the pointer
node* create(int n){
    node *head = NULL;
    head = (node*)(malloc(sizeof(node))); //typecasting
    head -> data = n;
    head -> next = NULL;
    return head;
    free(head);
}
void display(node *head){
    node *p = NULL;
    p = head;
    if (p == NULL){
        printf("Empty List \n");
    }
    while (p != NULL){
        printf("%i ->", p -> data);
        p = p -> next;
    }
    printf("\n");
}
node * insert (node *head, int n){
    node *temp = NULL;
    temp = (node*)(malloc(sizeof(node)));
    temp -> next = NULL;
    temp -> data = n;
    temp -> next = head;
    head = temp;
    return head;
    free(temp);
}
bool find(node *head,int n){
    node *p = NULL;
    p = head;
    while(p->next != NULL){
        p = p -> next;
        if (p-> data == n){
            printf("Found you\n");
            return true;
        }
    }
    printf("Could not find you\n");
    return false;
}

