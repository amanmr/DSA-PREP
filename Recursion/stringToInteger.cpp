#include<iostream>
using namespace std;

// "4283"-- 4283
int toInteger(string s,int n){
    if(n==0){
        return 0;
    }
    int smallerAns=toInteger(s,n-1);
    return smallerAns*10+(s[n-1]-'0');
}
int main()
{
    string s;
    cin>>s;
    cout<<toInteger(s,s.length());
    return 0;
}