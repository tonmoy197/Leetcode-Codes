// So we can conclude if a chain of adjacent O's is connected some O on boundary then they cannot be flipped
//1. Move over the boundary of board, and find O's 
      //2. Every time we find an O, perform DFS from it's position
      //3. In DFS convert all 'O' to '#'      (why?? so that we can differentiate which 'O' can be flipped and which cannot be)   
      //4. After all DFSs have been performed, board contains three elements,#,O and X
      //5. 'O' are left over elements which are not connected to any boundary O, so flip them to 'X'
      //6. '#' are elements which cannot be flipped to 'X', so flip them back to 'O'
      //7. finally, Upvote the solution

class Solution {
public:

    vector<int> sidex = {-1, 0, 1, 0};
    vector<int> sidey = { 0, 1, 0, -1};

    void dfs(vector<vector<char>>&board, int i, int j, int m, int n){   
        //handling corner case 
        if(!(i+1 <= m && i - 1 >= -1 && j + 1 <= n && j - 1 >= -1 )){
            return ;
        }

        //checking condition
        if(board[i][j] == '#' || board[i][j] == 'X') return;
        
        // applying dfs four side 
        board[i][j] = '#';
        for(int x = 0; x < 4; x ++){
            dfs(board, i+sidex[x], j+sidey[x], m , n);
        }

    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        // marking from left and right side '0
        for(int i = 0; i < m; i ++){
            dfs(board, i, 0 , m, n);
            dfs(board, i, n-1 , m, n);
        }
        // marking from top and bottom side '0
        for(int i = 0; i < n; i ++){
            dfs(board, 0, i, m, n);
            dfs(board, m-1, i , m, n);
            
        }

        // capturing region
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                if(board[i][j] == 'O' ) board[i][j] = 'X';
                if(board[i][j] == '#' ) board[i][j] = 'O';    
            }
        }

    }
};
