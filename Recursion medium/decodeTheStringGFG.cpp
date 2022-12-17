//{ Driver Code Starts
// Initial Template for C++
/*Input: s = 3[b2[ca]]
Output: bcacabcacabcaca
Explaination: 2[ca] means 'ca' is repeated
twice which is 'caca' which concatenated with
'b' becomes 'bcaca'. This string repeated
thrice becomes the output.*/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    string helper(string s, int i, int z)
    {
        if (s.length() == 0)
        {
            return s;
        }
        if (i > z)
        {
            return "";
        }
        if (s[i] == ']')
        {

            return helper(s, i + 1, z);
        }
        string tem="";
        if (isdigit(s[i]))
        {
            int loopcount = 0;
            int k = i + 1;
            loopcount = loopcount * 10 + (s[i] - '0');
            while (isdigit(s[k] && k <= z))
            {
                loopcount = loopcount * 10 + (s[i] - '0');
                k++;
            }
            tem = helper(s, k + 1, z - 1);
            string temp2;
            for (int j = 0; j < loopcount; j++)
            {
                temp2 += tem;
            }
            return temp2;
        }
        else
        {

            
            tem += s[i];
            int k = i + 1;

            while (k <= z)
            {
                if (!isdigit(s[k]) && s[k] != ']')
                {
                    tem += s[k];
                    k++;
                }
                else{
                    break;
                }
                
            }
            string small=helper(s, k, z);
            tem+=small;

            return tem;
        }
    }
    string decodedString(string s)
    {
        // code here
        string ans;
        map<string, pair<int, int>> dp;
        ans = helper(s, 0, (s.length() - 1));
        return ans;
    }
    /*string decodedString(string s)
    {
        // code here
        stack<char> stac;
        for(int i=0;i<s.length();i++){
            if(s[i]==']'){
                string temp;
                while(!stac.empty() && stac.top()!='['){
                    temp=stac.top()+temp;
                    stac.pop();
                }
                stac.pop();
                int loop=0;
                while(!stac.empty() && isdigit(stac.top())){
                    loop=loop*10+(stac.top()-'0');
                    stac.pop();
                }
                for(int k=0;k<loop;k++){
                    temp+=temp;
                }
                for(int k=0;k<temp.length();k++){
                    stac.push(temp[k]);
                }

            }
            else{
                stac.push(s[i]);
            }
        }
        string ans;
        while(!stac.empty()){
            ans=stac.top()+ans;
            stac.pop();
        }
        return ans;
    }*/
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";
    }
    return 0;
}
// } Driver Code Ends