#include<iostream>
using namespace std;

//2048 -- two zero four eight

string s[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
void iTos(int n){
    //base case
    if(n==0){
        return;
    }
    int rem=n%10;
    //calling for smaller part to move towards beginning of given number 
    iTos(n/10);
    //printing the value
    cout<<s[rem]<<endl;
}


int main()
{
    int n;
    //input number
    cin>>n;
    //calling recursive function
    iTos(n);
    return 0;
}