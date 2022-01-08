// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    public:
        string FirstNonRepeating(string A){
            // Code here
            string ans = "";
            int n = A.length();
            vector<int> visited(26,0);
            vector<char> order;
            for(int i=0;i<n;i++){
                if(!visited[A[i]-'a'])
                    order.push_back(A[i]);
                
                visited[A[i]-'a']++;
                int temp = 0;
                int size = order.size();
                for(int j=0;j<size;j++){
                    if(visited[order[j]-'a']==1){
                        temp = 1;
                        ans.push_back(order[j]);
                        break;
                    }
                }
                if(temp==0){
                    ans.push_back('#');
                }
            }
            return ans;
        }

};

// { Driver Code Starts.
int main(){
    int tc;
    cin >> tc;
    while(tc--){
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends