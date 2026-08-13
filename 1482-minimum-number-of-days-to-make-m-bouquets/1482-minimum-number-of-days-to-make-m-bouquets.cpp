class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size(),low=*min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int days=-1;
        while(low<=high){
            int cnt=0,bou=0;
            int mid=low+(high-low)/2;
            for(int i=0;i<n;i++){
                if(bloomDay[i]<=mid){
                    cnt++;

                }
                else{
                    bou=bou+(cnt/k);
                    cnt=0;
                }
                
            }
            bou=bou+(cnt/k);
            if(bou<m){
                low=mid+1;
            }
            else{
                days=mid;
                high=mid-1;
            }
        }
        return days;
    }
};