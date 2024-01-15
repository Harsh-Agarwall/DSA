#include <iostream>
#include <queue>
using namespace std;
int minSteps(string s, string t) {
        int count=s.length();
        for(int i=0;i<s.length();i++){
            for(int j=0;j<t.length();j++){
                 if(t[i]==s[j]){
                     count--;
                     s[j]='1';
                     break;
                 }
            }
        }
        cout<<s;
        return count;
    }

int main(){
    
string s="leetcode";
string t="practice";
cout<<minSteps(s,t);
    return 0;
}