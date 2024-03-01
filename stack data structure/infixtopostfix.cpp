#include<iostream>
#include<stack>
using namespace std;
int prec(char a){
    if(a=='^'){
        return 3;
    }
    else if(a=='*'||a=='/'){
        return 2;
    }
    else if(a=='+'||a=='-'){
        return 1;
    }
    else{
        return -1;
    }
}
string infix_to_postfix(string s){
    stack<char> st;
    string ans;
    for(int i=0;i<s.length();i++){
        if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
            ans+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty()&&st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty() && prec(st.top())>=prec(s[i])){
                ans+=st.top();
                st.pop();
                
            }st.push(s[i]);
        }
    }while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
}

int main(){

cout<<infix_to_postfix("(A*B-C^D^E/F+G/H)")<<endl;

    return 0;
}