class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n,1);
        vector<int>right(n,1);
        vector<int>ans(n,0);
        int a=1;
        for(int i=0;i<n;i++){
            if(i==0){
                left[0]=1;
                continue;
            }
            left[i]=left[i-1]*nums[i-1];
        }
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                right[n-1]=1;
                continue;
            }
            right[i]=right[i+1]*nums[i+1];
        }
        for(int i=0;i<n;i++){
            ans[i]=left[i]*right[i];
        }
        return ans;
    }
};