// given n friends. they can go either single or in pair on a bike. find no of ways.
#include<iostream>
using namespace std;

int pairs(int n){
    if(n<=1){
        return 1;
    }
   
    //going single
    int option1=pairs(n-1);
    //going in pair
    //(n-1)C1 for choosing 1 person from n-1 people
    int option2=(n-1)*pairs(n-2);
    return option1+option2;
}

int main()
{
    int n;
    cin>>n;
    cout<<pairs(n);
    return 0;
}