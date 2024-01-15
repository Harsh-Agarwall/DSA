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
int diameter(node* root,int *height){
    if(root==NULL){
        *height=0;
        return 0;
    }
    int lh=0, rh=0;
    int ldiameter=diameter(root->left,&lh);
    int rdiameter=diameter(root->right,&rh);
    int currdiameter=lh+rh+1;
    *height=max(lh,rh)+1;
    return max(ldiameter,max(rdiameter,currdiameter));


}
int main()
{
    node *root = new node(1);
    root->left=new node(2);
   
    root->left->left=new node(4);
    root->left->right=new node(3);
    root->left->left->left=new node(5);
    int height=0;
    cout<<diameter(root,&height);
   
    return 0;
}