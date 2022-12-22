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

pair<int,int> fastDiameter(node* root){
    if(root==NULL){
        return make_pair(0,0);
    }
    pair<int,int> t;
    pair<int,int> l=fastDiameter(root->left);
    pair<int,int> r=fastDiameter(root->right);
    t.first=max(l.first,r.first)+1;
    t.second=max(l.second,max(r.second,l.first+r.first));
    return t;

}

int main()
{
    node * root;
    root=buildtree();
    pair<int,int> ans;
    ans=fastDiameter(root);
    cout<<ans.second;
    return 0;
}
//8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1