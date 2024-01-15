#include<iostream>
using namespace std;
#define n 20
class queue{
    int *arr;
    int front;
    int rear;
    public:
    queue(){
        arr=new int[n];
        front=-1;
        rear=-1;
    }
    void enqueue(int d){
    if(rear==n-1){
        cout<<"queue overflow"<<endl;
return;
    }rear++;
    arr[rear]=d;
    if(front==-1){
        front++;
    }
}
    void dequeue(){
        if(front==-1||front>rear){
            cout<<"empty"<<endl;
            return;
        }front++;
}
void peek(){
    if(front==-1||front>rear){
            cout<<"empty"<<endl;
            return;
        }
        cout<<arr[front]<<endl;
}
bool empty(){
    if(front==-1||front>rear){
            cout<<"empty"<<endl;
            return true;
        }return false;
}
};

int main(){
queue q;
q.enqueue(2);
q.enqueue(4);
q.enqueue(5);
q.enqueue(6);
q.peek();
q.dequeue();
q.peek();
    return 0;
}