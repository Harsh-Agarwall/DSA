#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int data;
    struct Node *right;
    struct Node *left;

public:
    Node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};
Node* lca(Node * root,int n2,int n1){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }
    Node* leftlca=lca(root->left,n2,n1);
    Node* rightlca=lca(root->right,n2,n1);
    if(leftlca && rightlca){
        return root;
    }
    if(leftlca!=NULL){
        return leftlca;
    }
    return rightlca;

}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Node* i=lca(root,5,6);
    cout<<i->data;

    return 0;
}