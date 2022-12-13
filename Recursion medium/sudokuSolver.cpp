#include<iostream>
#include<cmath>
using namespace std;

bool place(int mat[9][9],int i,int j,int n,int k){
    //check row and column
    for(int a=0;a<n;a++){
        if(mat[i][a]==k){
            return false;
        }
        if(mat[a][j]==k){
            return false;
        }
    }
    
    //check 3*3 grid
    int rn=sqrt(n);
    int a=(i/rn)*3;
    int b=(j/rn)*3;
    for(int c=a;c<a+rn;c++){
        for(int d=b;d<b+rn;d++){
            if(mat[c][d]==k){
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int mat[9][9],int i,int j,int n){
    if(i==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }
    if(j==n){
        return solveSudoku(mat,i+1,0,n);
    }
    if(mat[i][j]!=0){
        return solveSudoku(mat,i,j+1,n);
    }
    for(int k=1;k<=9;k++){
        if(place(mat,i,j,n,k)){
            mat[i][j]=k;
            int smallerProblem;
            
                smallerProblem=solveSudoku(mat,i,j+1,n);
            if(smallerProblem){
                return true;
            }
            mat[i][j]=0;
        }
    }
    return false;
    
}

int main()
{
    int mat[9][9]={
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9},
    };
    bool ans=solveSudoku(mat,0,0,9);
    if(ans==0){
        cout<<"Answer not possible";
    }
    return 0;
}