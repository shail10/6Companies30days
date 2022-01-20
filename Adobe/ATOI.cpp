// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        int ans = 0;
        int temp = 0;
        for(int i=0;i<str.size();i++){
            if(str[i]>='0' and str[i]<='9')
                ans=ans*10 + (str[i]-'0');
            else if(isalpha(str[i]))
                return -1;
        }
        if(str[0] == '-') 
            return -ans;
        else
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
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.atoi(s)<<endl;
    }
}  // } Driver Code Ends