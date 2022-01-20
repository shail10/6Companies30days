// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    long long numOfWays(int n, int x)
    {
        // code here
        long long dp[n+1] = {0};
        dp[0] = 1;
        dp[1] = 1;
        int end = pow(n,1.0/x);
        for(int i=2;i<=end;i++){
            int temp = pow(i,x);
            for(int j=n;j>=temp;j--){
                dp[j] = dp[j]+dp[j-temp];
            }
        }
        return dp[n];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}
  // } Driver Code Ends