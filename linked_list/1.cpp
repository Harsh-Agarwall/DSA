#include<iostream>
using namespace std;
// for making linked list
class node{
    public:
    int data;
    node* next;

    node(int value){
        data=value;
        next=NULL;
    }};
    // for inserting at the head
    void insertathead(node* &head,int d){
        node* temp=new node(d);
        temp->next=head;
        head=temp;
    }
    // for insserting at the tail 
    void insertattail(node* &head,int d){
        node* temp=new node(d);
        node* temp2=head;
        while(temp2->next!=NULL){
            temp2=temp2->next;
        }
        temp2->next=temp;
        
    }
    // for printing the linked list 
void print(node* head){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }cout<<"NULL"<<endl;
    }
    // for searching the linked list 
bool search(node* &head,int key){
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }temp=temp->next;
    }return false;
}
// for deletion of item in the linked list 
void deletehead(node* &head){
    node* todelete=head;
    head=head->next;
    delete todelete;
}
void deletion(node* &head,int d){
    if(head==NULL){
        return;
    }if(head->next==NULL){
        deletehead(head);
        return;
    }
node* temp=head;
while(temp->next->data!=d){
    temp=temp->next;
}
node* todelete=temp->next;
temp->next=temp->next->next;
delete todelete;
}
// to reverse the linked list 
node* reverse(node* &head){
    node* previous=NULL;
    node* current=head;
    node* nextptr;
    while(current!=NULL){
         nextptr=current->next;
        current->next=previous;
        
        previous=current;
        current=nextptr;
    }return previous;

}
// to reverse the linked list using recursion 
node* rrecursive(node* &head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    node* newhead=rrecursive(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;


}
//reverseknode linked list
node* reversek(node* &head,int k){
    if(head==NULL){
        return NULL;
    }
    node* prevptr=NULL;
    node* currptr=head;
    node* next=NULL;
    int count=0;
    while(currptr!=NULL&&count<k ){
        
        next=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=next;
        count++;
    }
    if(next!=NULL){
        head->next=reversek(next,k);
    }
    return prevptr;
}
//to make cycle in linked list;
void makecycle(node* &head,int pos){
    node* temp=head;
    node* startnode;
    int count=0;
    while(temp->next!=NULL){
        if(count==pos){
            startnode=temp;
        }
        temp=temp->next;
        count++;
    }temp->next=startnode;
}
//to check does a cycle exist or not
bool check(node* &head){
    node* slow=head;
    node* fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}
//to remove cycle from the linked list
void removecycle(node* &head){
    node* slow=head;
    node* fast=head;
    do{
        slow=slow->next;
        fast=fast->next->next;
    }while(fast!=slow);
    fast=head;
    while(fast->next!=slow->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;

}



int main(){

node* node1=new node(5);
// cout<< node1 -> data<<endl;
// cout<<node1->next<<endl;
node* head=node1;
insertathead(head,4);
insertathead(head,6);
insertattail(head,8);
insertattail(head,1);
insertattail(head,2);
insertattail(head,7);
insertattail(head,7);
print(head);
makecycle(head,4);
cout<<check(head)<<endl;
removecycle(head);
cout<<check(head)<<endl;



    return 0;
}