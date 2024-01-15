#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
int height(node* root){
    if(root==NULL){
        return 0;
    }
    int lheight=height(root->left);
    int rheight=height(root->right);
    return max(lheight,rheight)+1;
}
bool check(node* root){
    if(root==NULL){
        return true;
    }
    if(check(root->left)==false){
        return false;
    }
    if(check(root->right)==false){
        return false;
    }

    int lheight=height(root->left);
    int rheight=height(root->right);
    if((lheight-rheight)<=1 && (lheight-rheight)>=-1){
        return true;
    }
    return false;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left=new node(6);
    root->left->left->right=new node(4);
    
    root->right->right = new node(3);
cout<<check(root);
    return 0;
}