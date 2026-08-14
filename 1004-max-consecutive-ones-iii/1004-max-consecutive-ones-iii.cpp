class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //maximum 2 zeroes are allowed
        int l=0,r=0,n=nums.size(),zero=0,maxi=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) zero++;
            while(zero>k){
                if(nums[l]==0){
                    zero--;
                }
                l++;
            }
            maxi=max(maxi,i-l+1);
        }
        return maxi;
    }
};