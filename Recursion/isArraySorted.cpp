#include<iostream>
using namespace std;

bool check(int *arr ,int n){
    if(n==1){
        return true;
    }
    int checkSmaller=check(arr+1,n-1);
    if(checkSmaller && arr[0]<=arr[1]){
        return true;
    }
    return false;
}

int main()
{
    int arr[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<check(arr,n);
    return 0;
}