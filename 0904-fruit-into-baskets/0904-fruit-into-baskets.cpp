class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mpp;
        int l=0, n=fruits.size();
        int maxlen=0;
        for(int i=0;i<n;i++){
            mpp[fruits[i]]++;

            if(mpp.size()>2){//with if condition here its lazy sliding window
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0) mpp.erase(fruits[l]);
                l++;
            }
            maxlen=max(maxlen,i-l+1);
        }
        return maxlen;
    }
};