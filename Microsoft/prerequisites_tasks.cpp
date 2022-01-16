// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:


    bool detectcycle(int i,vector<int> adj[], vector<int> &vis,vector<int> &dfsvis){
        dfsvis[i] = 1;
        vis[i] = 1;
        for(auto itr:adj[i]){
            if(!vis[itr]){
                if(detectcycle(itr,adj,vis,dfsvis)) return true;
            }
            else if(dfsvis[itr]){
                return true;
            }
        }
        dfsvis[i] = 0;
        return false;
    }

    bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
        // Code here
        //question on cycle detection
        vector<int> adj[N];
        for(auto itr:prerequisites){
            adj[itr.second].push_back(itr.first);
        }
        vector<int> vis(N,0);
        vector<int> dfsvis(N,0);
        for(int i=0;i<N;i++){
            if(!vis[i]){
                if(detectcycle(i,adj,vis,dfsvis))
                    return false;
            }
        }
        return true;
    }
};

// { Driver Code Starts.
int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends