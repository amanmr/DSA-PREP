#include<iostream>
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
void print(node * root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}
int heightoftree(node * root){
    if(root==NULL){
        return 0;
    }
    int op1=heightoftree(root->left);
    int op2=heightoftree(root->right);
    return max(op1,op2)+1;
}

int main()
{

    node * root;
    root=buildtree();
    print(root);
    cout<<endl;
    cout<<heightoftree(root);
    return 0;
}
//8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1