class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //if(m==0 ) return nums2;
        if(n==0) return;
        int p1=m-1,p2=n-1,k=m+n-1;
        while(p1>=0){
            if(p1>=0 && p2>=0){
                if(nums2[p2] > nums1[p1]){
                    nums1[k]=nums2[p2];
                    p2--;
                    k--;
                }
                else{
                    nums1[k]=nums1[p1];
                    k--;
                    p1--;
                }
            }
            if(p2<0) return;
        }
        while(p2>=0){
            nums1[k]=nums2[p2];
            p2--;
            k--;
        }
        return;
    }
};