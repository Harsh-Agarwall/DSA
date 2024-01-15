#include<iostream>
using namespace std;
#define n 100
class stack{
    int* arr;
    int top;
    public:
    stack(){
        arr=new int[n];
        top=-1;
    }
void push(int x){
    if(top==n-1){
        cout<<"stack overflow"<<endl;
        return;
    }top++;
    arr[top]=x;
}
void pop(){
    if(top==-1){
        cout<<"stack is empty"<<endl;
        return;
    }
    top--;
}
int Top(){
     if(top==-1){
        cout<<"stack is empty"<<endl;
        return -1;
    }
    return arr[top];
}
bool empty(){
    return top==-1;
}

};

int main(){
stack a;
a.push(1);
a.push(2);
a.push(3);
cout<<a.Top()<<endl;
a.pop();
cout<<a.Top()<<endl;
a.pop();
cout<<a.empty()<<endl;
a.pop();
cout<<a.empty()<<endl;


    return 0;
}