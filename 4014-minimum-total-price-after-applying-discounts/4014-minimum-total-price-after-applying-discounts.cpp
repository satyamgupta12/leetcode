class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(),prices.end(),greater<int>());
        sort(discounts.begin(),discounts.end(),greater<int>());
        double sum=0;
        int n=prices.size();
        int m=discounts.size();
        for(int i=0;i<n;i++){
            if(i<m){
                
                sum=sum+(prices[i]*(100.00-discounts[i])/100);
            }
            else
                sum=sum+prices[i];
        }
        return sum;
    }
};