#include<iostream>
using namespace std;

//nth fibonacci number
int fib(int n){
    //base case
    if(n==0 || n==1){
        return n;
    }
    //recurrence relation
    return fib(n-1)+fib(n-2);
}

int main()
{
    int n;
    //user input
    cin>>n;
    cout<<fib(n);
    return 0;
}