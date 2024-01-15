#include<iostream>
#include<stack>
using namespace std;
void reverse(string s){
    stack<string> st;
    
    for(int i=0;i<s.length();i++){
        string f="";
        while(s[i]!=' '&&i<s.length()){
            f+=s[i];
            i++;
        }st.push(f);
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}
int main(){
string s="hello how are you my friend";
reverse(s);
    return 0;
}