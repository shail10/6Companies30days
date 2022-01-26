class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<int> adj[numCourses];
        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        
        vector<int> indegree(numCourses,0);
        
        for(int i=0;i<pre.size();i++){
            indegree[pre[i][0]]++;
        }
        
        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        
        vector<int> ans;
        
        while(!q.empty()){
            int i = q.front();
            q.pop();
            ans.push_back(i);
            for(auto itr:adj[i]){
                indegree[itr]--;
                if(indegree[itr]==0)
                    q.push(itr);
            }
        }
        if(ans.size()!=numCourses)
            ans.clear();
        return ans;
    }
};