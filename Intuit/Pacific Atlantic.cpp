class Solution {
public:
    
    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<bool>>& ocean, int prev){
        if(i<0||i>=heights.size()||j<0||j>=heights[0].size()||ocean[i][j]||heights[i][j]<prev)
            return;
        ocean[i][j] = true;
        dfs(i+1,j,heights,ocean,heights[i][j]);
        dfs(i-1,j,heights,ocean,heights[i][j]);
        dfs(i,j+1,heights,ocean,heights[i][j]);
        dfs(i,j-1,heights,ocean,heights[i][j]);
        
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>> pac(r,vector<bool> (c,false));
        vector<vector<bool>> atl(r,vector<bool> (c,false));
        
        for(int i=0;i<r;i++){
            dfs(i,0,heights,pac,INT_MIN);
            dfs(i,c-1,heights,atl,INT_MIN);
        }
        
        for(int j=0;j<c;j++){
            dfs(0,j,heights,pac,INT_MIN);
            dfs(r-1,j,heights,atl,INT_MIN);
        }
        
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(atl[i][j]==true and pac[i][j]==true)
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};