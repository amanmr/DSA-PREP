/*
Input : 
array = {1, 2, 3}
Output :
// this space denotes null element. 
1
1 2
1 2 3
1 3
2
2 3
3
*/


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    void helper(vector<int>& inp, vector<int> &sub,vector<vector<int> > &ans,int n,int i){
        ans.push_back(sub);
        for(int k=i;k<n;k++){
            sub.push_back(inp[k]);
            helper(inp,sub,ans,n,i+1);
            sub.pop_back();
        }
        return;
    }
    
    vector<vector<int> > subsets(vector<int>& inp)
    {
        //code here
        vector<vector<int> > ans;
        int n=inp.size();
        vector<int> sub;
        helper(inp,sub,ans,n,0);

        return ans;

    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}
// } Driver Code Ends