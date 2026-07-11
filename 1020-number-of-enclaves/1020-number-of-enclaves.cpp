class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(i==0 || j==0 || i==grid.size()-1 || j==grid[0].size()-1){
                    if(!vis[i][j] && grid[i][j]==1)
                    dfs(i,j,grid,vis);
                }
                
            }
        }
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && !vis[i][j]) cnt++;
            }
        }
        return cnt;

    }
    
    void dfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>>&vis){
        int delrow[]={0,1,0,-1};
    int delcol[]={-1,0,1,0};
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int nr=delrow[i]+r;
            int nc=delcol[i]+c;
            if(nr>=0 && nr<grid.size() && nc >=0 && nc<grid[0].size() && grid[nr][nc]==1 && !vis[nr][nc]) dfs(nr,nc,grid,vis);
         }
    }
};