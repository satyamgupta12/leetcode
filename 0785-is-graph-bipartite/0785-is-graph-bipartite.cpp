class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int>q;
        vector<int>coloured(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(coloured[i]==-1){
                q.push(i);
                coloured[i]=0;
            }
        
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            bool color=(bool)coloured[temp];
            for(auto it : graph[temp]){ //not colored
                if(coloured[it]==-1){
                    q.push(it);
                    coloured[it]=!color;
                }
                else{ //already colored chk
                    if(coloured[it]==color){
                        return false;
                    }

                }
            }
        }
    }
    return true;
    }
};