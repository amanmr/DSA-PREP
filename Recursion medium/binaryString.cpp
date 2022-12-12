// find no of binary string of length n without having consecutive 1
// for n=2 --> {(0,0),(1,0),(0,1)} --> (1,1) is not included because it has consecutive 1's
#include<iostream>
using namespace std;

int  bstring(int n,int lastDigit){
    if(n==0)
    return 0;
    if(n==1){
        if(lastDigit==0){
            return 2;
        }
        else{
            return 1;
        }
    }
    if(lastDigit==0){
        return bstring(n-1,0)+bstring(n-1,1);
    }
    else{
        return bstring(n-1,0);
    }
}

int main()
{
    int n;
    cin>>n;
    cout<<bstring(n,0);
    return 0;
}