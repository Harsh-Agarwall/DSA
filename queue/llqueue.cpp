#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(int val){
        data=val;
        next=NULL;
    }
};
class queue{
    
    node *front;
    node *rear;
    public:
    queue(){
        front=NULL;
        rear=NULL;
    }
void enqueue(int d){
    node* n=new node(d);
    if(front==NULL){
        front=n;
        rear=n;
        return;
    }
    rear->next=n;
    rear=n;
}
void dequeue(){
    if(front==NULL){
        cout<<"queue is empty"<<endl;
        return;
    }
    node* todelete=front;
    front=front->next;
    delete(todelete);
}
void peek(){
    if(front==NULL){
        cout<<"queue is empty"<<endl;
        return;
    }
    cout<<front->data;

}
bool empty(){
    if(front==NULL){
        return true;
    }return false;
}
};
int main(){
queue q;
q.enqueue(1);
q.enqueue(2);
q.enqueue(3);
q.peek();
q.dequeue();
q.peek();

    return 0;
}