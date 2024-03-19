class Solution {
public:
    vector<int> sidex = {-1, 0, 1, 0};
    vector<int> sidey = { 0, 1, 0, -1};

    void dfs(vector<vector<int>>&heights, vector<vector<bool>>&visited, int i, int j, int m, int n, int src){   
        //handling corner case 
        if(!(i+1 <= m && i - 1 >= -1 && j + 1 <= n && j - 1 >= -1 )){
            return ;
        }
        if(visited[i][j]) return ;


        // checking condition 
        if(heights[i][j] < src ) return;
        
        // applying dfs four side 
        visited[i][j] = true;
        for(int x = 0; x < 4; x ++){
            dfs(heights, visited, i+sidex[x], j+sidey[x], m , n, heights[i][j]);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        // creating matrices to mark visited cells
        vector<vector<bool>> pacific(m, vector<bool>(n)), atlantic(m, vector<bool>(n));

        // dfs traversal from top and bottom 
        for(int i = 0; i < n; i ++){
            dfs(heights, pacific, 0, i, m, n, 0);
            dfs(heights, atlantic, m-1, i, m, n, 0 );
        }

        // dfs traversal from left and right
        for(int i = 0; i < m; i ++){
            dfs(heights, pacific, i, 0, m, n, 0 );
            dfs(heights, atlantic, i, n-1, m, n, 0);
        }

        // finding the ans vector
        vector<vector<int>> ans;
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++ ){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i, j});
                } 
            }
        }

        return ans;
        
    }
};