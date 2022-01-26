class Solution {
public:
    
    bool solve(vector<int> &nums, int m, int mid){
        int total = 0;
        int subarrays = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>mid)
                return false;
            if(nums[i]+total<=mid)
                total+=nums[i];
            else{
                subarrays++;
                total = nums[i];
            }
        }
        subarrays++;
        return (subarrays<=m);
    }
    
    int splitArray(vector<int>& nums, int m) {
        int l = 0;
        int r = (int)(1e9+1);
        
        while(l<r){
            int mid = (l+r)/2;
            if(solve(nums,m,mid))
                r = mid;
            else
                l = mid+1;
        }
        return r;
    }
};