// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    // int dp[1001][1001];

    int coin(int i,int j, vector<int> &arr,vector<vector<int>> &dp){
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int m = arr[i] + min(coin(i+2,j,arr,dp),coin(i+1,j-1,arr,dp));
        int n = arr[j] + min(coin(i,j-2,arr,dp),coin(i+1,j-1,arr,dp));
        return dp[i][j] = max(m,n);
    }

    int maxCoins(vector<int>&A,int n)
    {
        //Write your code here
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return coin(0,n-1,A,dp);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}
  // } Driver Code Ends