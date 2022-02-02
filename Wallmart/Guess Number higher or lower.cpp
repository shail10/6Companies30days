class Solution {
public:
    
    int dp[201][201];
    
    int solve(int i, int j){
        if(i>=j)
            return 0;
        if(dp[i][j]!=0)
            return dp[i][j];
        
        int temp = INT_MAX;
        for(int itr=i;itr<=j;itr++){
            temp = min(temp,itr+max(solve(i,itr-1),solve(itr+1,j)));
        }
        return dp[i][j] = temp;
    }
    
    
    int getMoneyAmount(int n) {
        memset(dp,0,sizeof(dp));
        return solve(1,n);
    }
};