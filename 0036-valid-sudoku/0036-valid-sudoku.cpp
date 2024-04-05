class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // checking for each row
        for(int i = 0; i < 9; i ++){
            set<char> st;
            for(int j = 0; j < 9; j ++){
                if(board[i][j] =='.') continue;
                if(st.find(board[i][j]) == st.end()){
                    st.insert(board[i][j]);
                }
                else return false;
            }
        }

        // checking for each column
        for(int i = 0; i < 9; i ++){
            set<char> st;
            for(int j = 0; j < 9; j ++){
                if(board[j][i] =='.') continue;
                if(st.find(board[j][i]) == st.end()){
                    st.insert(board[j][i]);
                }
                else return false;
            }
        }

        // check for each three square 
        vector<pair<int, int>> ps = {{0,0},{0,3},{0,6},{3,0},{3,3},{3,6},{6,0}, {6,3}, {6,6}};
        vector<pair<int, int>> pe = {{2,2},{2,5},{2,8},{5,2},{5,5},{5,8},{8,2}, {8,5}, {8,8}};

        for(int i = 0; i < 9; i ++){
            int xs = ps[i].first, xe = pe[i].first;
            int ys = ps[i].second, ye = pe[i].second;
            set<char> st;
            for(int j = xs; j <= xe; j ++){
                for(int k = ys; k <= ye; k ++){
                    if(board[j][k] =='.') continue;
                    if(st.find(board[j][k]) == st.end()){
                        st.insert(board[j][k]);
                    }
                    else return false;
                }
            }
        }

        return true;
    }
};