#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};
void insert_at_head(node* &head,int d){
    node* n=new node(d);
    node* temp=head;
    if(head==NULL){
        n->next=n;
        head=n;
        return;
    }
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    head=n;
}
void insert_at_tail(node* &head,int d){
    if(head==NULL){
        insert_at_head(head,d);
        return;
    }
    node* n=new node(d);
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
}
void delete_at_head(node* &head){
node* todelete;
node* temp=head;
while(temp->next!=head){
    temp=temp->next;
}todelete=head;
temp->next=head->next;
head=head->next;
delete todelete;

}
void deletee(node* &head,int pos){
    if(pos==1){
        delete_at_head(head);
        return;
    }
    node* todelete;
    node* temp=head;
    int count=1;
    while(count!=pos-1){
        temp=temp->next;
        count++;
    }
    todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
    }
void print(node* &head){
    node* temp=head;
    do{
        cout<<temp->data<<"->";
        temp=temp->next;
}while(temp!=head);
cout<<"NULL";
}
int main(){
node* head=NULL;
insert_at_tail(head,1);
insert_at_tail(head,2);
insert_at_tail(head,3);
insert_at_tail(head,4);
insert_at_head(head,5);
insert_at_head(head,6);
deletee(head,1);
print(head);

    return 0;
}