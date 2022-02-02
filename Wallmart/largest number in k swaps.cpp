// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    
    void solve(string &ans, string &str, int k, int idx){
        if(idx==str.size())
            return;
        if(k==0)
            return;
        int maxx = str[idx] - '0';
        for(int i=idx+1;i<str.size();i++){
            if(maxx<str[i]-'0')
                maxx = str[i]-'0';
        }
        if(maxx!=str[idx]-'0')
            k--;
        
        for(int i=str.size()-1;i>=idx;i--){
            if(str[i]-'0' == maxx){
                swap(str[idx],str[i]);
                ans=max(ans,str);
                solve(ans,str,k,idx+1);
                swap(str[idx],str[i]);
            }
        }
    }
    
    
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       // code here.
       string ans = str;
       solve(ans,str,k,0);
       return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends