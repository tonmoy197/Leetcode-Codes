class Solution {
    
public:
    bool dfs(int u, vector<vector<int>>&g , vector<int> &vis  ){
        vis[u] = 1;
        for (auto v : g[u]){
            if(vis[v] == 0){
                if(dfs(v, g, vis)) return true;
            }
            else if(vis[v] == 1){
                return true;
            }
        }

        vis[u] = 2;
        return false;
    } 

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> vis(n+1);
        vector<vector<int>> g(n+1);
        for(int i = 0; i < prerequisites.size(); i ++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            g[v].push_back(u);
        }
        
        for(int i = 0; i < numCourses; i++){
            if(vis[i]==0){
                if(dfs(i, g, vis)) return false;
            }
        }
        return true;
    }
};