class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        queue<pair<int,int>> q;
        
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        int count = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    dp[i][j]=0;
                    q.push({i,j});
                    count++;
                }
                else if(grid[i][j] == 0)
                    dp[i][j] = INT_MAX;
            }
        }
        if(count==0 || count==n*n)
            return -1;
        
        int ans = INT_MIN;
        while(!q.empty()){
            auto itr = q.front();
            int x = itr.first;
            int y = itr.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx>=0 and nx<n and ny>=0 and ny<n and dp[nx][ny]>dp[x][y]+1){
                    dp[nx][ny] = dp[x][y] + 1;
                    q.push({nx,ny});
                    ans = max(ans,dp[nx][ny]);
                }
            }
        }
        return ans;
    }
};