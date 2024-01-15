#include<iostream>
#include<queue>
using namespace std;
struct Node{
    int data;
    struct Node*left;
    struct Node*right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
int rightcount1(Node* root){
    static int co=0;
    Node* n=root->right;
    if(n==NULL){
        return co;
    }
    co++;
    
    rightcount1(n);

    

}
int leftcount(Node* root){
    static int count=0;
    Node* n=root->left;
    if(n==NULL){
        return count;
    }
    count++;
    int g=rightcount1(n);
    leftcount(n);

    return count+g;
    
}
int leftcount1(Node* root){
    static int cou=0;
    Node* n=root->left;
    if(n==NULL){
        return cou;
    }
    cou++;
    leftcount1(n);

    return cou;
    
}
int rightcount(Node* root){
    static int c=0;
    Node* n=root->right;
    if(n==NULL){
        return c;
    }
    c++;
    int g=leftcount1(n);
    rightcount(n);

    return c+g;

}
int count(Node* root){
int j=leftcount(root)+rightcount(root)+1;


return j;
}
int countc(Node* root){
    if(root==NULL){
        return 1;
    }
return (countc(root->left)+countc(root->right)+1);
}
int main(){
Node *root=new Node(1);
root->left=new Node(2);
root->right=new Node(3);
root->left->left=new Node(4);
root->left->right=new Node(5);
root->right->left=new Node(6);
root->right->right=new Node(7);
root->left->left->left=new Node(9);
root->left->left->right=new Node(0);

cout<<countc(root);
    return 0;
}