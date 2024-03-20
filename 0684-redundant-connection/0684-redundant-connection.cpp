class Solution {
public:

    // NOTE: 
    // 1. if a two different node has same parent then there is a cycle

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        // Union and find method
        vector<int> ds(n + 1);
        for(int i = 0; i <= n; i ++) ds[i] = i;

        for(int i = 0; i < n; i ++){
            int u = edges[i][0]; // 1
            int v = edges[i][1]; // 2

            // finding main parent of an element 
            int par1 = findPar(u, ds);
            int par2 = findPar(v, ds);

            // if both have same parent 
            if(par1 == par2 ) return {u, v}; 
            else {
                ds[par2] = par1;
            }

        }

        return {};
    }

    // to find the first parent 
    int findPar(int u, vector<int> &ds){
        if(ds[u] == u) return u;
        return findPar(ds[u], ds);
    }


};