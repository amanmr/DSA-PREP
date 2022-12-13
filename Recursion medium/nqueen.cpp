#include<iostream>
using namespace std;

//check whether we can place queen at ith row and jth column
bool place(int arr[10][10],int i,int j,int n){
    //checking column
    for(int k=0;k<i;k++){
        if(arr[k][j]==1){
            return false;
        }
    }
    int a=i;
    int b=j;
    //checking left diagonal
    while(a>=0 && b>=0){
        if(arr[a][b]==1){
            return false;
        }
        a--;
        b--;
    }
    a=i;
    b=j;
    //checking right diagonal
    while(a>=0 && b<n){
        if(arr[a][b]==1){
            return false;
        }
        a--;
        b++;
    }
    //possible
    return true;

}

bool nQueen(int arr[][10],int n,int i){
    //base case placed all queens
    if(i==n){
        for(int a=0;a<n;a++){
            for(int b=0;b<n;b++){
                if(arr[a][b]==1){
                    cout<<"Q"<<" ";
                }
                else{
                    cout<<"_ ";
                }
            }
            cout<<endl;
        }
        cout<<endl;
        return false;
    }
    //iterating over columns for ith queen
    for(int k=0;k<n;k++){
        if(place(arr,i,k,n)){
            arr[i][k]=1;
            bool isNQueenPossible=nQueen(arr,n,i+1);
            if(isNQueenPossible){
                return true;
            }
            arr[i][k]=0;
        }
    }
    return false;
    
}

int main()
{
    int n;
    cin>>n;
    int arr[10][10]={0};
    bool ans=nQueen(arr,n,0);
    return 0;
}