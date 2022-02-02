class Solution {
public:
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<pair<int,double>> adj[n];
        int m = edges.size();
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        
        
        priority_queue<pair<int,double>> q;
        q.push({start,1});
        vector<double> ans_v(n,INT_MIN);
        
        while(!q.empty()){
            int node = q.top().first;
            double prob = q.top().second;
            q.pop();
            
            for(auto temp:adj[node]){
                int child_node = temp.first;
                double child_node_prob = temp.second;
                
                if(child_node_prob*prob > ans_v[child_node]){
                    ans_v[child_node] = child_node_prob*prob;
                    q.push({child_node,ans_v[child_node]});
                }
            }
        }
        if(ans_v[end] != INT_MIN)
            return ans_v[end];
        return 0;
    }
};