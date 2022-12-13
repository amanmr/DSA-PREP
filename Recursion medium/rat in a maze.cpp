//printing all the possible paths
#include<iostream>
using namespace std;

bool ratInAMaze(char maze[10][10],int sol[10][10],int i,int j,int m,int n){
    if(i==m-1 && j==n-1){
        sol[i][j]=1;
        for(int a=0;a<m;a++){
            for(int b=0;b<n;b++){
                cout<<sol[a][b];
            }
            cout<<endl;
        }
        cout<<"--------------------------------"<<endl;
        return true;
    }
    if(i>=m || j>=n){
        return false;
    }
    
    if(maze[i][j]=='X' ){
        return false;
    }
    bool f,b;
    sol[i][j]=1;
    
    f=ratInAMaze(maze,sol,i+1,j,m,n);
    b=ratInAMaze(maze,sol,i,j+1,m,n);
    sol[i][j]=0;
    if(f||b){
        return true;
    }
    return false;
    
}

int main()
{
    char maze[10][10]={
        "0000",
        "00X0",
        "000X",
        "0X00"
    };

    int solution[10][10]={0};
    
    int sol=ratInAMaze(maze,solution,0,0,4,4);
    if(!sol){
        cout<<"Path not possible";
    }
    return 0;
}