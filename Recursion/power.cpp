#include <iostream>
using namespace std;

int pow(int n, int p)
{
    //base case
    if (p == 0)
    {
        return 1;
    }
    //recursive case
    return n * pow(n, p - 1);
}

int main()
{
    int n, p;
    cout << "Enter base and pow respectively(integer)" << endl;
    cin >> n>> p;
    cout << pow(n, p);
    return 0;
}