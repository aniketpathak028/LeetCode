class Solution {
public:
    bool vis[201][201];
    bool flag[201][201];
    void dfs(int i, int j, vector<vector<char>>& grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='X' || vis[i][j]) return;
        vis[i][j]=1;
        flag[i][j]=0;
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1, grid);
        dfs(i,j-1, grid);
    }
    void solve(vector<vector<char>>& board) {
        memset(vis, 0, sizeof(vis));
        memset(flag, 1, sizeof(flag));
        
        for(int j=0; j<board[0].size(); ++j){
            if(!vis[0][j] && board[0][j]=='O') dfs(0, j, board);
        }
        
        for(int j=0; j<board[0].size(); ++j){
            if(!vis[board.size()-1][j] && board[board.size()-1][j]=='O') dfs(board.size()-1, j, board);
        }
        
        for(int i=0; i<board.size(); ++i){
            if(!vis[i][0] && board[i][0]=='O') dfs(i, 0, board);
        }
        
        for(int i=0; i<board.size(); ++i){
            if(!vis[i][board[0].size()-1] && board[i][board[0].size()-1]=='O') dfs(i, board[0].size()-1, board);
        }
        
        for(int i=0; i<board.size(); ++i){
            for(int j=0; j<board[0].size(); ++j){
                if(board[i][j]=='O' && flag[i][j]==1) board[i][j]='X';
            }
        }
    }
};