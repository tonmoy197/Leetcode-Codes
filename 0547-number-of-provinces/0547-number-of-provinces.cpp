class Solution {
public:

    void dfs(vector<vector<int>>&g, int u, vector<int>& vis){
        vis[u] = true;
        for(auto v: g[u]){
            if(!vis[v]) dfs(g, v, vis);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        //making graph
        vector<vector<int>> g(n+1);
        vector<int> vis(n+1);

        for(int i = 0; i < n; i ++ ){
            for(int j = 0; j < n; j ++){
                if(isConnected[i][j] == 1){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }

        // finding number of isolated graph
        int ans = 0;
        for(int i = 0; i < n; i ++){
            if(!vis[i] ){
                dfs(g, i, vis );
                ans ++;
            }
        }

        return ans;



        
    }
};