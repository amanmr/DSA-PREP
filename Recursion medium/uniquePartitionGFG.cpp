//{ Driver Code Starts
//4-----{4}  {3,1}   {2,2}   {2,1,1}   {1,1,1,1}
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:

    void helper(int n,int k,list<int> v,vector<vector<int>> &ans){
        if(k==0){
            vector<int> l;
            v.pop_front();
            for(auto x:v){
                l.push_back(x);
            }
            ans.push_back(l);
            v.push_front(INT_MAX);
            return;
        }
        for(int i=k;i>0;i--){
            if(v.back()>=i){
                v.push_back(i);
                helper(n,k-i,v,ans);
                v.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> UniquePartitions(int n) {
        // Code here
        vector<vector<int>> ans;
        list<int> v;
        v.push_back(INT_MAX);
        helper(n,n,v,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		vector<vector<int>> ans = ob.UniquePartitions(n);
    	for(auto i : ans)
    		for(auto j: i)
    			cout << j <<" ";
    	cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends