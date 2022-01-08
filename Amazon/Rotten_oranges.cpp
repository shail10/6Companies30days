class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // we will apply bfs here
        if(grid.empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        int total = 0;
        
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] != 0) total++;
                if(grid[i][j] == 2) q.push({i,j});
            }
        }
        //create array for the neighbour of any x,y
        int X[4] = {0,0,1,-1};
        int Y[4] = {1,-1,0,0};
        int count = 0;
        int days = 0;
        
        while(!q.empty()){
            int temp = q.size();
            count+=temp;
            while(temp--){
                int x = q.front().first, y = q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nx = x+X[i];
                    int ny = y+Y[i];
                    if(nx<0||ny<0||nx>=m||ny>=n||grid[nx][ny]!=1) continue;
                    grid[nx][ny] = 2;
                    q.push({nx,ny});
                }
            }
            if(!q.empty())
                days++;
        }
        if(count==total)
            return days;
        else
            return -1;
    }
};