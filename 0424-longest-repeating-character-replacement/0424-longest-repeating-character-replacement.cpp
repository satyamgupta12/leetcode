class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0;
        int n=s.size();
        int maxlen=0,maxfreq=0;
        unordered_map<char,int>mpp;

        for(int i=0;i<n;i++){
            mpp[s[i]]++;
            maxfreq=max(maxfreq,mpp[s[i]]);
            int changes=(i-l+1)-maxfreq;
            while(changes>k){
                mpp[s[l]]--;
                if(mpp[s[l]]==0) mpp.erase(s[l]);
                l++;
                maxfreq=0;
                for(auto it: mpp){
                     maxfreq=max(maxfreq,it.second);
                }
                changes=(i-l+1)-maxfreq;
            }
            
            if(changes<=k){ // good
                maxlen=max(maxlen,i-l+1);
            }
        }
        return maxlen;
    }
};