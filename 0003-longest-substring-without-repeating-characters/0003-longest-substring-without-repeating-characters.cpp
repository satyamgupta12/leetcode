class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char>us;
        int n=s.size();
        if(n==0) return 0;
        int l=0,r=0,maxi=0;
        for(int i=0;i<n;i++){
            while(us.find(s[i])!=us.end()){
                us.erase(s[l]);
                l++;
            }
                us.insert(s[i]);
            maxi=max(maxi,i-l+1);
        }
        return maxi;
    }
};