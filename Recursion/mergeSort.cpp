#include<iostream>
using namespace std;

void merge(int arr[],int s,int mid,int e){
    int c[e-s+1];
    int i=s,j=mid,k=0;
    while(i<mid && j<=e){
        if(arr[i]<arr[j]){
            c[k++]=arr[i++];
        }
        else{
            c[k++]=arr[j++];
        }
    }
    while(i<mid){
        c[k++]=arr[i++];
    }
    while(j<=e){
        c[k++]=arr[j++];
    }
    for(int i=0;i<(e-s+1);i++){
        arr[s+i]=c[i];
    }
    return;
    
}

void mergeSort(int arr[],int s,int e){
    if(s>=e){
        return;
    }
    int mid=(s+e)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,mid+1,e);
}

int main()
{
    int n;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}