#include<iostream>
using namespace std;

int firstOcc(int arr[],int n,int key){
    if(n==0){
        return -1;
    }
    if(arr[0]==key){
        return 0;
    }
    int smallerPart=firstOcc(arr+1,n-1,key);
    if(smallerPart!=-1){
        return smallerPart+1;
    }
    return -1;
}

int main()
{
    int n,key;
    cout<<"Enter no of items"<<endl;
    cin>>n;
    int arr[100];
    cout<<"Enter array elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter key value"<<endl;
    cin>>key;
    cout<<"found at index - "<<firstOcc(arr,n,key);
    return 0;
}