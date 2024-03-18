class Solution {
public:
    vector<int> sidex = {-1, 0, 1, 0};
    vector<int> sidey = { 0, 1, 0, -1};

    void dfs(vector<vector<char>>&grid, int i, int j, int m, int n){   
        //handling corner case 
        if(!(i+1 <= m && i - 1 >= -1 && j + 1 <= n && j - 1 >= -1 )){
            return ;
        }
        if(grid[i][j] == '0') return ;
        
        
        // applying dfs four side 
        grid[i][j] = '0';
        for(int x = 0; x < 4; x ++){
            dfs(grid, i+sidex[x], j+sidey[x], m , n);
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // finding number of isolated graph
        int ans = 0;
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++ ){
                if(grid[i][j] == '1' ){
                    dfs(grid, i, j, m , n);
                    ans ++;
                }
            }
            
        }

        return ans;
        
    }
};