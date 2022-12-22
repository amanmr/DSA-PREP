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

int heightoftree(node * root){
    if(root==NULL){
        return 0;
    }
    int op1=heightoftree(root->left);
    int op2=heightoftree(root->right);
    return max(op1,op2)+1;
}

void printkthlevel(node * root,int k){
    if(root==NULL){
        return;
    }
    if(k==1){
        cout<<root->data<<" ";
    }
    printkthlevel(root->left,k-1);
    printkthlevel(root->right,k-1);
    return;
}

int main()
{

    node * root;
    root=buildtree();
    int height=heightoftree(root);
    for(int i=1;i<=height;i++){
        printkthlevel(root,i);
        cout<<endl;
    }
    
    return 0;
}
//8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1