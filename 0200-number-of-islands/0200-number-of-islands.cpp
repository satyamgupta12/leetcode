class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row= grid.size();
        int column= grid[0].size();

        vector<vector<int>>visited(row,vector<int>(column,0));
        int cnt=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,visited,grid);
                }
            }
        } 
        return cnt;
    }
    void bfs(int row,int column,vector<vector<int>>&visited,vector<vector<char>>&grid){
        visited[row][column]=1;
        queue<pair<int,int>>q;
        q.push({row,column});
        while(!q.empty()){
            int nrow=q.front().first;
            int ncol= q.front().second;
            q.pop();

            for(int delrow=-1;delrow<=1;delrow++){
                for(int delcol=-1;delcol<=1;delcol++){
                    if(abs(delrow) + abs(delcol) != 1)
                    continue;

                   int neighrow=nrow+delrow;
                   int neighcol=ncol+delcol;
                   if(neighrow>=0 && neighrow<grid.size() && neighcol>=0 && neighcol<grid[0].size() && grid[neighrow][neighcol]=='1' && !visited[neighrow][neighcol]){
                    visited[neighrow][neighcol]=1;
                    q.push({neighrow,neighcol});
                   }

                }
            }
        }

    }
};