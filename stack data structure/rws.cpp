#include<iostream>
#include<stack>
using namespace std;
void reverse(string s){
    stack<char> st;
    for(int i=0;i<s.length();i++){
        st.push(s[i]);
    }while(!st.empty()){
        cout<<st.top();
        st.pop();
    }cout<<endl;
}
int main(){
string s="hello my friend";
reverse(s);
    return 0;
}