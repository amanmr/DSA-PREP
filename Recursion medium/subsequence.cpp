//find all subsequence of given string
#include<iostream>
using namespace std;

void subseq(char a[],char b[],int i,int j){
    if(a[i]=='\0'){
        b[j]='\0';
        cout<<b<<endl;
        return;
    }
    //not considering ith character
    subseq(a,b,i+1,j);
    //considering ith character
    b[j]=a[i];
    subseq(a,b,i+1,j+1);
}
int main()
{
    char a[]="abc";
    char b[100];
    subseq(a,b,0,0);
    return 0;
}