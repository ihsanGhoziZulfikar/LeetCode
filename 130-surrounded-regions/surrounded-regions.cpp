class Solution {
public:
    map<pair<int,int>,int> safe;
    void dfs(int x, int y, vector<vector<char>> board){
        if(x>=0 && y>=0 && x<board.size() && y<board[x].size() && !safe[{x,y}] && board[x][y] == 'O'){
            // cout << x << " - " << y << ": " << board[x][y] << endl;
            safe[{x,y}]=1;
            dfs(x-1,y,board);
            dfs(x+1,y,board);
            dfs(x,y-1,board);
            dfs(x,y+1,board);
        }
    }

    void solve(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            if(board[i][0]=='O' && !safe[{i,0}]){
                dfs(i,0,board);
            }
            if(board[i][board[0].size()-1]=='O' && !safe[{i,board[0].size()-1}]){
                dfs(i,board[0].size()-1,board);
            }
        }
        for(int j=0;j<board[0].size();j++){
            if(board[0][j]=='O' && !safe[{0,j}]){
                dfs(0,j,board);
            }
            if(board[board.size()-1][j]=='O' && !safe[{board.size()-1,j}]){
                dfs(board.size()-1,j,board);
            }
        }

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]=='O' && !safe[{i,j}]){
                    board[i][j] = 'X';
                }
            }
        }

        // for(auto const &it: safe){
        //     cout << it.first.first << " " << it.first.second << ": " << it.second << endl;
        // }
    }
};