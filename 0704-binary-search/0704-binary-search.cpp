class Solution {
public:
    int search(vector<int>& nums, int target) {
    int low=0;
    int high=nums.size()-1;
    while(low<=high){
        int n = low+(high-low)/2;
        if(nums[n]==target) return n;
        else if(nums[n]<target){
            low=n+1;
        }
        else high=n-1;
    }
    return -1;
}
};