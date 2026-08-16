class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        vector <int>mpp(3,-1);
        int cnt=0;

        for(int i=0;i<n;i++){
            mpp[s[i]-'a']=i;
            if(mpp[0]!=-1 && mpp[1]!=-1 && mpp[2]!=-1){
    
                int mini = min({mpp[0], mpp[1], mpp[2]});
        
                cnt+=mini+1;
            }
        }
        return cnt;
    }
};