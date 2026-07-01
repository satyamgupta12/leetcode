class Solution {
private:
    void dfs(int node,vector<vector<int>>&adjLis,vector<int>&visited){
        visited[node]++;
        for(auto it : adjLis[node]){
            if(!visited[it]){
            dfs(it,adjLis,visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // FIRSTLY convert into adjacency list
        
        int n= isConnected.size();
        vector<int>visited(n,0);
        vector<vector<int>>adjLis(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjLis[i].push_back(j);
                    adjLis[j].push_back(i);
                }
            }
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                cnt++;
                dfs(i,adjLis,visited);
            }
        }
        return cnt;
    }
};