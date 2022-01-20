// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    #define p pair<int,pair<int,int>>
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
        priority_queue<p,vector<p>,greater<p>> q;
        int mn = INT_MAX, mx=INT_MIN, range = INT_MAX;
        int low=0;
        int high=0;
        
        for(int i=0;i<k;i++){
            q.push({arr[i][0],{i,0}});
            mn = min(mn,arr[i][0]);
            mx = max(mx,arr[i][0]);
        }
        
        while(!q.empty()){
            p temp = q.top();
            q.pop();
            int mini = temp.first;
            if(range>mx-mini){
                mn = mini;
                range = mx-mn;
                low = mn;
                high = mx;
            }
            
            int i = temp.second.first;
            int j = temp.second.second;
            
            if(j==n-1)
                break;
            
            q.push({arr[i][j+1],{i,j+1}});
            mx = max(mx,arr[i][j+1]);
        }
        return {low,high};
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
        rangee = obj.findSmallestRange(arr, n, k);
        cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
    return 0;
}

  // } Driver Code Ends