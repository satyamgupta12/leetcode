class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]==target) return mid;

            if(nums[low]<=nums[mid]){//sorted
                if(nums[low]<=target && target<nums[mid]){ //normal binary search
                    high=mid-1;
                }
                else low=mid+1;
            }
            else{
                //right sort
                if(target >nums[mid] && target<=nums[high]){
                    low=mid+1;
                }
                else high=mid-1;
            }
        }
        return -1;
    }
};