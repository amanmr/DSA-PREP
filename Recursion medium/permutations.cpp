//"abc"----"abc","acb","bac","bca","cab","cba"
#include<iostream>
#include<string.h>
using namespace std;

void permutations(char str[],char ans[],int i,int j){
    if(str[i]=='\0'){
        ans[j]='\0';
        cout<<ans<<endl;
        return;
    } 
    for(int k=i;k<strlen(str);k++){
        swap(str[i],str[k]);
        ans[j]=str[i];
        
        permutations(str,ans,i+1,j+1);
    }
    return;
}

int main()
{
    char string[]="abcd";
    char ans[100];
    permutations(string,ans,0,0);
    return 0;
}