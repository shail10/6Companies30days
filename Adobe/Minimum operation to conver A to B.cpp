// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  
    int solve(vector<int> &a,int n){
        int dp[n+1];
        for(int i=1;i<=n;i++)
            dp[i] = INT_MAX;
        dp[0] = INT_MIN;
        for(int i=0;i<n;i++){
            int idx = upper_bound(dp,dp+n+1,a[i])-dp;
            if(a[i]>dp[idx-1] and a[i]<dp[idx])
                dp[idx] = a[i];
        }
        int ans = 0;
        for(int i=n;i>=0;i--){
            if(dp[i] != INT_MAX){
                ans = i;
                break;
            }
        }
        return ans;
    }
  
  
    int minInsAndDel(int A[], int B[], int N, int M) {
        // code here
        unordered_map<int,int> mp;
        for(int i=0;i<M;i++){
            mp[B[i]]++;
        }
        
        vector<int> v;
        for(int i=0;i<N;i++){
            if(mp.find(A[i]) != mp.end()){
                v.push_back(A[i]);
                mp[A[i]]--;
            }    
        }
        int n = v.size();
        int ans = solve(v,n);
        return M+N-2*ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        cin>>N>>M;
        
        int A[N], B[M];
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<M; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.minInsAndDel(A,B,N,M) << endl;
    }
    return 0;
}  // } Driver Code Ends