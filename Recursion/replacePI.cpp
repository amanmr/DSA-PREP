// "abcpidepi" -- "abc3.14de3.14"
#include <iostream>
#include<string.h>
using namespace std;

void replacePI(char s[], int i, int n)
{
    if (i == strlen(s))
    {
        return;
    }
    if (s[i] == 'p' && s[i + 1] == 'i')
    {
        for (int j = n; j > i + 1; j--)
        {
            s[j + 2] = s[j];
        }
        s[i] = '3';
        s[i + 1] = '.';
        s[i + 2] = '1';
        s[i + 3] = '4';
        replacePI(s,i+4,n);
    }
    replacePI(s,i+1,n);
}

int main()
{
    char s[100];
    cin>>s;
    int n=strlen(s);
    s[n]='\0';
    replacePI(s,0,n);
    cout << s;
    return 0;
}