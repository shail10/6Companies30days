// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        vector<int> mod(k,0);
        for(int i=0;i<nums.size();i++)
            mod[nums[i]%k]++;
        if(mod[0]%2!=0)
            return false;
            
        int start = 1;
        int end = k-1;
        while(start<=end)
        {
            if(start==end && mod[start]%2==1)
                return false;
            else if(mod[start]!=mod[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends