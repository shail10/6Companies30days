// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long



class Solution{
public:	
  
	unsigned long long getNthUglyNo(int n) {
	    ull ans[n+1];
	    ans[1] = 1;
	    ull p2 = 1;
	    ull p3 = 1;
	    ull p5 = 1;
	    for(int i=2;i<=n;i++)
	    {
	        ull a2 = 2*ans[p2];
	        ull a3 = 3*ans[p3];
	        ull a5 = 5*ans[p5];
	        ull newNumber = min(a2,min(a3,a5));
	        ans[i] = newNumber;
	        if(newNumber == a2)
	            {p2++;}
	        if(newNumber == a3)
	            {p3++;}
	        if(newNumber == a5){
	            p5++;
	        }
	    }
	    return ans[n];
	}
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
