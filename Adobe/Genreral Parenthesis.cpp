// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    vector<string> ans;
    void paranthesis(string &temp, int open, int close){
        if(open==0 and close==0){
            ans.push_back(temp);
            return;
        }
        if(open!=0){
            string temp1 = temp;
            temp1.push_back('(');
            paranthesis(temp1,open-1,close);
        }
        if(close>open){
            string temp2 = temp;
            temp2.push_back(')');
            paranthesis(temp2,open,close-1);
        }
    }
    
    
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        int open = n;
        int close = n;
        string temp = "";
        paranthesis(temp,open,close);
        return ans;
    }
};

// { Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        vector<string> result = ob.AllParenthesis(n); 
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); ++i)
            cout<<result[i]<<"\n";
    }
    return 0; 
} 
  // } Driver Code Ends