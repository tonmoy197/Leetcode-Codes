class Solution {
    

public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        int n = numCourses;
        vector<bool> vis(n+1);
        vector<vector<int>> g(n+1);
        vector<int> indeg(n+1);
        for(int i = 0; i < prerequisites.size(); i ++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            indeg[u]++;
            g[v].push_back(u);
        }
        
        // Topological shortin using kann's algorithm
        vector<int> ans;
        bool possible = true;
        while(ans.size() < n){

            // finding curr element which indeg is zero
            int curr = -1;
            for(int i = 0; i < n; i ++){
                if(!vis[i] && indeg[i] == 0){
                    curr = i;
                    break;
                } 
            }

            // if curr not found so that topological sorting not possible
            if(curr == -1 ) {
                possible = false;
                break;
            }

            // decreasing indegree of a adjacent nodes by one
            vis[curr] = true;
            for(auto u : g[curr]) indeg[u]--;

            ans.push_back(curr);
        }

        vector<int> notans;
        if(possible) return ans;
        return notans;
        
    }
};