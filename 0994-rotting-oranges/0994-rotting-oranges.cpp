class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // to check possible or not
        int tot = 0, cnt = 0;

        // queue for the bfs storing co-ordinate
        queue<pair<int,int>> q;

        // finding total number of orange
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                if(grid[i][j] != 0) tot ++;
            }
        }

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = { 0, 1, 0, -1};

        // to store answer, update after each iteration
        int ans = 0;
        while(!q.empty()){
            int k = q.size();
            cnt += k;
            while( k -- ){
                // Taking 1st pair from the queue
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                // checking four side of the rotten cell
                for(int i = 0; i < 4; i ++){
                    // solving corner cases
                    int nx = x + dx[i], ny = y + dy[i];
                  
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                        continue;
                    if( grid[nx][ny] != 1) continue; 

                    grid[nx][ny] = 2;
                    q.push({nx, ny});

                }
            }
            if(!q.empty()) ans++;
        }

        if(tot == cnt ) return ans;
        return -1;

    }
};