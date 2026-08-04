class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        int n=arr.size();
        //int lb=lower_bound(arr.begin(),arr.end(),target)-arr.begin();
        //int up=upper_bound(arr.begin(),arr.end(),target)-arr.begin();
        int lb=lower(arr,target);
        int up=upper(arr,target);
        if(lb==n || arr[lb]!=target){
            return {-1,-1};
        }
        return{lb,up-1};
    }
    int lower(vector<int>& arr, int target){
        int low= 0;
        int high=arr.size()-1;
        int ans=arr.size();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>=target){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    int upper(vector<int>& arr, int target){
        int low= 0;
        int high=arr.size()-1;
        int ans=arr.size();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>target){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};