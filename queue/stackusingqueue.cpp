#include<iostream>
#include<queue>
using namespace std;
class stack{
    int n;
    queue<int> q1;
    queue<int> q2;
    public:
    stack(){
        n=0;
    }
    void push(int val){
        q2.push(val);
        n++;
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp=q1;
        q1=q2;
        q2=temp;
    }
    void pop(){
        q1.pop();
        n--;
    }
    void display(){
        cout<<q1.front()<<endl;
    }
};
int main(){
stack st;
st.push(1);
st.push(2);
st.push(3);
st.display();
st.pop();
st.display();
    return 0;
}