#include<iostream>
using namespace std;

int maxProfit(int w[],int p[],int n,int c){
    //base case
    if(n==0 || c==0){
        return 0;
    }
    int include=0,exclude=0;
    //including n-1th item 
    if(c>=w[n-1]){
        include=p[n-1]+maxProfit(w,p,n-1,c-w[n-1]);
    }
    //excluding profit of n-1th item
    exclude=maxProfit(w,p,n-1,c);
    return max(include,exclude);
}

int main()
{
    int weight[]={1,2,3,5};
    int profit[]={20,40,60,70};
    int capacity=6;
    int n=4;
    cout<<maxProfit(weight,profit,n,capacity);
    return 0;
}