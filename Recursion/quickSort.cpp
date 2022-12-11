#include<iostream>
using namespace std;


int partition(int arr[],int s,int e){
    int p=e;
    int i=s,j=e-1;
    while(i<j){
        while(arr[i]<=arr[p] && i<e){
            i++;
        }
        while(arr[j]>arr[p] && j>=s){
            j--;
        }
        if(i<=j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i],arr[p]);
    return i;
}

void quickSort(int arr[],int s,int e){
    if(s>=e){
        return;
    }
    int pivot=partition(arr,s,e);
    quickSort(arr,s,pivot-1);
    quickSort(arr,pivot+1,e);
}

int main()
{
    int n;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}