// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
    int minDifference(int arr[], int n)  { 
        // Your code goes here
        int total = 0;
        for(int i=0;i<n;i++)
            total+=arr[i];
        int min = total/2;
        //vector<vector<bool>> dp(n+1,vector<bool> total+1);
        bool dp[n+1][total+1];
        //Initializing the dp
        for(int j=0;j<=total;j++)
            dp[0][j] = false;
        for(int i=0;i<=n;i++)
            dp[i][0] = true;
        
        //From here the dp starts
        for(int i=1;i<=n;i++){
            for(int j=1;j<=total;j++){
                if(arr[i-1]<=j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        vector<int> v;
        for(int i=0;i<=total/2;i++){
            if(dp[n][i] == true)
                v.push_back(i);
        }
        int mini = INT_MAX;
        for(int i=0;i<v.size();i++){
            int temp = total - 2*v[i];
            if(temp<mini)
                mini = temp;
        }
        return mini;
    } 
};


// { Driver Code Starts.
int main() 
{
   
   
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];

       

        Solution ob;
        cout << ob.minDifference(a, n) << "\n";
         
    }
    return 0;
}  // } Driver Code Ends