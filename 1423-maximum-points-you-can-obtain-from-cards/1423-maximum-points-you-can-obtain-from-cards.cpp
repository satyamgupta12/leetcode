class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int l=0,r=n-1,maxscore=0,sum=0;
       for(int i=0;i<k;i++){//making window of k
            if(i<k){
                sum+=cardPoints[i];
            }
       }
        maxscore=max(maxscore,sum);  
        for(int i=k-1;i>=0;i--){
            sum=sum-cardPoints[i]+cardPoints[r];
            r--;
            maxscore=max(maxscore,sum);  
        }  
       return maxscore;
    }
};