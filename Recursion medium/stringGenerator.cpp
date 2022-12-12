// Given input string "123". Generate all the character strings that are possible.
// 1 is mapped to 'a',  2 is mapped to 'b' and so on.
// for "123"
//(1)(2)(3)--- abc
//(12)(3)  --- mc
//(1)(23)  --- aw

#include <iostream>
using namespace std;

void generateS(char in[], char out[], int i, int j)
{
    //base case
    if (in[i] == '\0')
    {
        out[j] = '\0';
        cout << out << endl;
        return;
    }
    //taking only first digit of input string
    int fd = in[i] - '0';
    out[j] = 'A' + fd - 1;
    generateS(in, out, i + 1, j + 1);
    //taking first two digits of input string only possible if second digit is not null
    if (in[i + 1] != '\0')
    {
        int sd = in[i + 1] - '0';
        int num = fd * 10 + sd;
        if (num <= 26)
        {
            out[j] = 'A' + num - 1;
            generateS(in, out, i + 2, j + 1);
        }
    }
}

int main()
{
    char in[100];
    char out[100];
    cin >> in;
    generateS(in, out, 0, 0);
    return 0;
}