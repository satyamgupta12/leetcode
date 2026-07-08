class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int r=board.size();
        int c=board[0].size();
        vector<vector<int>>vis(r,vector<int>(c,0));
        for (int i=0;i<c;i++){
           
            if(board[0][i]=='O' && !vis[0][i]){
                dfs(0,i,board,vis);
            }
            if(board[r-1][i]=='O' && !vis[r-1][i])
                dfs(r-1,i,board,vis); 
        }
        for (int j=0;j<r;j++){
           
            if(board[j][0]=='O' && !vis[j][0]){
                dfs(j,0,board,vis);
            }
            if(board[j][c-1]=='O' && !vis[j][c-1])
                dfs(j,c-1,board,vis);
        } 
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]=='O' && !vis[i][j]) board[i][j]='X';
            }
        }
    }
    
    void dfs(int r,int c,vector<vector<char>>& board,vector<vector<int>>&vis){
        vis[r][c]=1;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr= r +delrow[i];
            int nc=c+delcol[i];
            if(nr>=0 && nr<board.size() && nc>=0 && nc<board[0].size() && board[nr][nc]=='O' && !vis[nr][nc]){
                dfs(nr,nc,board,vis);
            }
        }
    }
};