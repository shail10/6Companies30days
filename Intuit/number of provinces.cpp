class Solution {
public:
    
    void dfs(vector<int> adj[], int i, vector<bool>& vis){
        if(vis[i])
            return;
        vis[i] = true;
        for(auto itr:adj[i]){
            dfs(adj,itr,vis);
        }
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1)
                    adj[i].push_back(j);
            }
        }
        
        vector<bool> vis(n,false);
        int ans=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!vis[i]){
                    ans++;
                    dfs(adj,i,vis);
                }
            }
        }
        return ans;
    }
};