
#include <bits/stdc++.h>
using namespace std;






class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long p = 1;
        int end=0,ans=0;
        for(int i=0;i<n;i++){
            p = p*a[i];
            while(end<n && p>=k){
                p = p/a[end];
                end++;
            }
            ans=ans+(i-end+1);
        }
        return ans;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
