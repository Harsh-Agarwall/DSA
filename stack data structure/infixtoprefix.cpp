#include<iostream>
#include<stack>
#include <algorithm>
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
string infix_to_prefix(string s){
    reverse(s.begin(),s.end());
    stack <char> st;
    string ans;
    for(int i=0;i<s.length();i++){
        if(s[i]>='a'&&s[i]<='z'){
            ans+=s[i];
        }else if(s[i]==')'){
            st.push(s[i]);
        }else if(s[i]=='('){
            while(!st.empty()&&st.top()!=')'){
                ans+=st.top();
                st.pop();
            }if(!st.empty()){
                st.pop();
            }
        }else{
            while((!st.empty())&&(prec(st.top())>prec(s[i]))){
                ans+=st.top();
                st.pop();
            }st.push(s[i]);
        }
    }while(!st.empty()){
        ans+=st.top();
        st.pop();
    }reverse(ans.begin(),ans.end());
    return ans;

}

int main(){
cout<<infix_to_prefix("(a-b/c)*(a/k-l)");


    return 0;
}