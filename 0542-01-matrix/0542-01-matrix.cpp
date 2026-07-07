class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m=mat[0].size();
        vector<vector<int>>res(n,vector<int>(m,0));
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(mat[i][j]==0 && !vis[i][j]){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        int delrow []={0,1,0,-1};
        int delcol []={-1,0,1,0};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int d=q.front().second;
            q.pop();
            res[r][c]=d;
            for(int i=0;i<4;i++){
                int nr=delrow[i]+r;
                int nc=delcol[i]+c;
                if(nr>=0 && nr<n && nc >= 0 && nc<m && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    
                    q.push({{nr,nc},d+1});
                }
            }
        }
        return res;
    }
};