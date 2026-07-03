class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        

        int row= image.size();
        int column= image[0].size();

        vector<vector<int>>visited(row,vector<int>(column,0));
        int check = image[sr][sc];
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                if(!visited[i][j] && image[i][j]==check){
                    bfs(sr,sc,visited,image,color,check);
                }
            }
        } 
        return image;
    }
    void bfs(int row,int column,vector<vector<int>>&visited,vector<vector<int>>&image,int color,int check){
        visited[row][column]=1;
        image[row][column]=color;
        queue<pair<int,int>>q;
        q.push({row,column});
        while(!q.empty()){
            int nrow=q.front().first;
            int ncol= q.front().second;
            q.pop();

            for(int delrow=-1;delrow<=1;delrow++){
                for(int delcol=-1;delcol<=1;delcol++){
                    if(abs(delrow)+abs(delcol)!=1) continue;

                   int neighrow=nrow+delrow;
                   int neighcol=ncol+delcol;
                   if(neighrow>=0 && neighrow<image.size() && neighcol>=0 && neighcol<image[0].size() && image[neighrow][neighcol]==check && !visited[neighrow][neighcol]){
                    visited[neighrow][neighcol]=1;
                    q.push({neighrow,neighcol});
                    image[neighrow][neighcol]=color;
                   }

                }
            }
        }



    }
};