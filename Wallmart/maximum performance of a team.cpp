class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> arr;
        for(int i = 0;i<n;i++){
            arr.push_back({efficiency[i],speed[i]});
        }
        int mod = 1e9+7;
        sort(arr.rbegin(),arr.rend());
        
        priority_queue<int,vector<int>,greater<int>> q;
        
        int ans = 0;
        int sp = 0;
        
        for(auto temp:arr){
            int curr_eff = temp.first;
            int curr_sp = temp.second;
            sp = sp+curr_sp;
            q.push(curr_sp);
            if(q.size()>k){
                sp-=q.top();
                q.pop();
            }
            ans = max(ans,sp*curr_eff);
        }
        return (ans%mod);
    }
};