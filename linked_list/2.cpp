#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};
void insert_at_head(node* &head,int d){
    node* n=new node(d);
    node* temp=head;
    
    if(head!=NULL){
    head->prev=n;
    }n->next=head; 
    head=n;
}
void insert_at_tail(node* &head,int d){
    if(head==NULL){
        insert_at_head(head,d);
        return;
    }
    node* n=new node(d);
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}
void print(node* &head){
    node* temp=head;
    while(temp->next!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }cout<<"NULL";
}

void deletion_at_head(node* &head){
    node* todelete=head;
    head=head->next;
    head->prev=NULL;
    delete todelete;
}
void deletion(node* &head,int pos){
    if(pos==1){
        deletion_at_head(head);
    }
    node* temp=head;
    int count=0;
    while(temp!=NULL&&count!=pos){
        temp=temp->next;
        count++;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    delete temp;
}
int main(){

node* head=NULL;

insert_at_tail(head,1);
insert_at_tail(head,2);
insert_at_tail(head,3);
insert_at_tail(head,4);
insert_at_tail(head,5);
insert_at_head(head,0);

deletion(head,1);
print(head);
    return 0;
}