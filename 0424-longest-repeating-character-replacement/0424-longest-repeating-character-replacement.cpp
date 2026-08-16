class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), l = 0;
        int maxlen = 0;
        int maxi = 0;

        unordered_map<char, int> mpp;

        for(int i = 0; i < n; i++) {
            mpp[s[i]]++;

            maxi = max(maxi, mpp[s[i]]);

            if((i - l + 1) - maxi > k) {
                mpp[s[l]]--;

                if(mpp[s[l]] == 0)
                    mpp.erase(s[l]);

                l++;
            }

            maxlen = max(maxlen, i - l + 1);
        }

        return maxlen;
    }
};