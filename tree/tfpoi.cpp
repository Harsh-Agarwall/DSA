#include<iostream>
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
int search(int inorder[],int start,int end,int curr){
    for(int i=0;i<=end;i++){
        if(inorder[i]==curr){
            return i;
        }
        
    }return -1; 
}
Node* buildtree(int postorder[],int inorder[],int start,int end)
{
static int idx=6;
if(start>end){
    return NULL;
}
int curr=postorder[idx];
Node* node=new Node(curr);
idx--;
if(start==end){
return node;
}
int pos=search(inorder,start,end,curr);
node->right=buildtree(postorder,inorder,pos+1,end);
node->left=buildtree(postorder,inorder,start,pos-1);
return node;
}
void inorder_print(Node* root){
    if(root==NULL){
        return;
    }
    inorder_print(root->left);
    cout<<root->data<<" ";
    inorder_print(root->right);
}

int main(){
int postorder[]={4,5,2,6,7,3,1};
int inorder[]={4,2,5,1,6,3,7};
Node* root=buildtree(postorder,inorder,0,6);
inorder_print(root);
 


    return 0;
}