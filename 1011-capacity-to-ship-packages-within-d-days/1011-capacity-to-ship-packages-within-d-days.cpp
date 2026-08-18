class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=reduce(weights.begin(),weights.end(),0);
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int calDays=NoOfDays(weights,mid); // mid represents load of ship
            if(calDays<=days){
                ans=mid;
                high=mid-1;
            }
            else{
            
                low=mid+1;
            }
        }
        return ans;
    }
    int NoOfDays(vector<int>& weights, int load){
        int n=weights.size();
        int totalweights=0;
        int days=1;
        for(int i=0;i<n;i++){
            if(load>=totalweights+weights[i]){
                totalweights+=weights[i];

            }
            else{
                days++;
                totalweights=weights[i];
            }
        }
        return days;
    }
};