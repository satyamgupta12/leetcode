class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int r=board.size();
        int c=board[0].size();
        vector<vector<int>>vis(r,vector<int>(c,0));
        for (int i=0;i<r;i++){
           for(int j=0;j<c;j++){
            if(i==0||j==0||i==r-1||j==c-1){
                if(board[i][j]=='O' && !vis[i][j]){
                    dfs(i,j,board,vis);
                }
            }
        }
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