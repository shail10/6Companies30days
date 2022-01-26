class Solution {
public:
    
    bool solve(int mid, vector<int>& weights, int days){
        int total = 0;
        int subarrays = 0;
        for(int i=0;i<weights.size();i++){
            if(weights[i]>mid)
                return false;
            if(total+weights[i]<=mid)
                total+=weights[i];
            else{
                subarrays++;
                total = weights[i];
            }
        }
        subarrays++;
        return (subarrays<=days);
    }
    
    
    int shipWithinDays(vector<int>& weights, int days) {
        //This question is similar to minimizing the largest sum in array;
        int r = 0;
        for(int i=0;i<weights.size();i++)
            r+=weights[i];
        int l = 0;
        while(l<r){
            int mid = l + (r-l)/2;
            if(solve(mid,weights,days)){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};