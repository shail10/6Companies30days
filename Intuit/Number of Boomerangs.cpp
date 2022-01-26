class Solution {
public:
    
    double solve(int x1, int x2, int y1, int y2){
        return (sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)));
    }
    
    int numberOfBoomerangs(vector<vector<int>>& points) {
        unordered_map<int,unordered_map<double,int>> mp;
        for(int i=0;i<points.size();i++){
            for(int j=0;j<points.size();j++){
                double dis = solve(points[i][0],points[j][0],points[i][1],points[j][1]);
                mp[i][dis]++;
            }
        }
        int ans = 0;
        for(auto itr1:mp){
            for(auto itr2:itr1.second){
                ans += (itr2.second)*(itr2.second-1);
            }
        }
        return ans;
    }
};