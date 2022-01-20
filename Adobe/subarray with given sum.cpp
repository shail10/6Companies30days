// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        int i = 0;
        int j = 0;
        vector<int> ans;
        long long sum = arr[0];
        while(i<n and j<n){
            if(sum == s){
                ans.push_back(i+1);
                ans.push_back(j+1);
                return ans;
            }
            else if(sum<s){
                sum+=arr[++j];
            }
            else if(sum>s){
                sum-=arr[i];
                i++;
            }
        }
        return {-1};
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
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
    return 0;
}  // } Driver Code Ends