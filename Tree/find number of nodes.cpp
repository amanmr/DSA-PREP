#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;
    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

node* buildtree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    node * root=new node(d);
    root->left=buildtree();
    root->right=buildtree();
    return root;
}
int sum(node * root){
    if(root==NULL){
        return 0;
    }
    int op1,op2;
    op1=sum(root->left);
    op2=sum(root->right);
    return root->data+op1+op2;
}





int main()
{

    node * root;
    root=buildtree();
    cout<<sum(root);
    return 0;
}
//8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1