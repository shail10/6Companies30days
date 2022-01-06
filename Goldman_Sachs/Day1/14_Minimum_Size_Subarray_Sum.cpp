class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int start = 0;
        int end = 0;
        int min = INT_MAX;
        
        while(end<n)
        {
            while(end<n && sum<target)
                sum = sum + nums[end++];
            
            while(start<n && sum>=target)
            {
                if(end-start < min)
                    min = end-start;
                sum = sum - nums[start++];
            }
        }
        if(min!=INT_MAX)
            return min;
        else
            return 0;
    }
};