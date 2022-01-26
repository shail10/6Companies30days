class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> zeros(n,-1);
        for(int i=0;i<n;i++){
            int zero = 0;
            int j = n-1;
            while(j>=0 && grid[i][j] == 0){
                zero+=1;
                j--;
            }
            zeros[i] = zero;
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            if(zeros[i] < n-i-1){
                int j = i+1;
                while(j<n && zeros[j]<n-i-1)
                    j++;
                
                if(j==n)
                    return -1;
                
                while(j>i){
                    swap(zeros[j],zeros[j-1]);
                    j--;
                    ans++;
                }
            }
        }
        return ans;
    }
};