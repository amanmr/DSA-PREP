#include<iostream>
#include<string>
using namespace std;

void balancedP(char c[],int n,int open,int close,int i){
    if(i==n){
        c[i]='\0';
        cout<<c<<endl;
        return;
    }
    if(open<(n/2)){
        c[i]='(';
        balancedP(c,n,open+1,close,i+1);
    }
    if(open>close){
        c[i]=')';
        balancedP(c,n,open,close+1,i+1);
    }
}

int main()
{
    int n;
    cin>>n;
    char c[n+1];

    balancedP(c,n,0,0,0);
    return 0;
}