#include<iostream>

using namespace std;

int bSearch(int arr[],int s,int e,int key){
    if(s>e){
        return -1;
    }
    int mid=(s+e)/2;
    if(arr[mid]==key){
        return mid;
    }
    if(key>mid){
        return bSearch(arr,mid+1,e,key);
    }
    else{
        return bSearch(arr,s,mid-1,key); 
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cin>>key;
    cout<<bSearch(arr,0,n-1,key);
    return 0;
}