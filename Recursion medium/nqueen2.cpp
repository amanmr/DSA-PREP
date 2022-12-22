//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool place(int board[][100], int n, int i, int j)
    {
        for (int a = 0; a < i; a++)
        {
            if (board[a][j] == 1)
            {
                return false;
            }
        }
        int a, b;
        a = i;
        b = j;
        while (a >= 0 && b >= 0)
        {

            if (board[a][b] == 1)
            {
                return false;
            }
            a--;
            b--;
        }
        a = i;
        b = j;
        while (a >= 0 && b < n)
        {
            if (board[a][b] == 1)
            {
                return false;
            }
            a--;
            b++;
        }
        return true;
    }
    bool helper(int board[][100], int n, int i, vector<int> subsol,vector<vector<int>> &sol)
    {
        if (i == n)
        {
            
            sol.push_back(subsol);
            return false;
        }
        for (int j = 0; j < n; j++)
        {
            if (place(board, n, i, j))
            {
                board[i][j] = 1;
                subsol[j]=i+1;
                bool smallerans = helper(board, n, i + 1,subsol,sol);
                if (smallerans)
                {
                    return true;
                }
                else
                {
                    board[i][j] = 0;
                    subsol[j]=0;
                }
            }
        }
        return false;
    }
    vector<vector<int>> nQueen(int n)
    {
        // code here
        vector<vector<int>> sol;
        vector<int> subsol(n,0);
        int board[100][100] = {0};
        bool ans = helper(board, n, 0, subsol,sol);
        return sol;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends