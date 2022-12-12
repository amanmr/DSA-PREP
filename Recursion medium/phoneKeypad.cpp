//in phone keypad 1 is mapped to "abc" 2 is mapped to "def" and so on;
// if input is "23", we need to output all possible combinations; 


#include<iostream>
#include<string>
using namespace std;

string keys[]={"","","abc","def","ghi","jkl","mno","prqs","tuv","wxyz"};

void keypad(char in[],char out[],int i,int j){
    if(in[i]=='\0'){
        out[j]='\0';
        cout<<out<<endl;
        return;
    }
    int num=in[i]-'0';
    int k=0;
    while(keys[num][k]!='\0'){
        out[j]=keys[num][k];
        keypad(in,out,i+1,j+1);
        k++;
    }


}

int main()
{
    
    char in[100];
    char out[100];
    cin>>in;
    keypad(in,out,0,0);
    return 0;
}