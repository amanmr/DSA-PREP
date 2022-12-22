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

void bfs(node * root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        
        node * temp=q.front();
        if(temp==NULL){
            
            q.pop();
            cout<<endl;
            if(q.empty()){
                break;
            }
            q.push(NULL);
            continue;
        }
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    return;
}




int main()
{

    node * root;
    root=buildtree();
    bfs(root);
    return 0;
}
//8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1