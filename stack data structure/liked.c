#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *insert(struct node *head, int value){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=value;
    if (temp==NULL){
        printf("Memory is full\n");
    }
    else if (head==NULL){
        head=temp;
        temp->next=NULL;
    }
    else{
        struct node *p;
        p=head;
        while(p->next){
            p=p->next;
        }
        p->next=temp;
        temp->next=NULL;
    }
    return head;
}

void display(struct node *head){
    struct node *p;
    p=head;
    if (p==NULL){
        printf("list is empty\n");
    }
    else{
        while(p){
            printf("%d ",p->data);
            p=p->next;
        }
    }
}

int main(){
    struct node *head=NULL;

    head=insert(head,69);
    head=insert(head,5);
    head=insert(head,8);
    head=insert(head,77);
    head=insert(head,22);
    display(head);
    return 0;
}