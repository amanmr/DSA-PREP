//given 4*n sized wall. We have two tiles of size 1*4 and 4*1. 
//What are the ways to arranrge these two tiles on the given wall.
#include<iostream>
using namespace std;

int ways(int n){
    if(n==0){
        return 1;
    }
    if(n==1 || n==2 || n==3){
        return 1;
    }
    return ways(n-1)+ways(n-4);
}

int main()
{
    int n;
    cin>>n;
    cout<<ways(n);   
    return 0;
}