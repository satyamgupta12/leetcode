class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size(),low=*min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int days=-1;
        if(1ll* m * k > n)
            return -1;
        while(low<=high){
            int conse=0,bou=0;
            int mid=low+(high-low)/2;
            for(int i=0;i<n;i++){
                if(bloomDay[i]<=mid){
                    conse++;

                }
                else{
                    bou=bou+(conse/k);
                    conse=0;
                }
                
            }
            bou=bou+(conse/k);
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