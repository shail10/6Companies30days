class Solution {
public:
    
    bool solve(vector<int>& piles, int h, int mid){
        int hours = 0;
        for(int i=0;i<piles.size();i++){
            hours+= ceil((double)piles[i]/mid);
        }
        return hours<=h;
    
    }
    
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = INT_MIN;
        int n = piles.size();
    
        
        for(int i=0;i<n;i++)
            r = max(r,piles[i]);
        
        while(l<r){
            int mid = l + (r-l)/2;
            
            if(solve(piles,h,mid)){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};