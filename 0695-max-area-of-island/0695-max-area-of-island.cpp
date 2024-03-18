class Solution {
public:
    vector<int> sidex = {-1, 0, 1, 0};
    vector<int> sidey = { 0, 1, 0, -1};

    void dfs(vector<vector<int>>&grid, int i, int j, int m, int n, int &count){   
        //handling corner case 
        if(!(i+1 <= m && i - 1 >= -1 && j + 1 <= n && j - 1 >= -1 )){
            return ;
        }
        if(grid[i][j] == 0) return ;
        
        
        // applying dfs four side 
        grid[i][j] = 0;
        count ++;
        for(int x = 0; x < 4; x ++){
            dfs(grid, i+sidex[x], j+sidey[x], m , n, count);
        }

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // finding number of isolated graph
        int ans = 0;
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++ ){
                if(grid[i][j] == 1 ){
                    int count = 0;
                    dfs(grid, i, j, m , n, count);
                    ans = max(ans, count);
                }
            }
            
        }

        return ans;
        
    }
};