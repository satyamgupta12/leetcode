class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //priority_queue<int> pq; tales o(nlogn ) time 
        priority_queue<int> pq(stones.begin(), stones.end());  //takes o(n) time 
    
        while(pq.size()>=2){
            int first=pq.top();
            pq.pop();
            int second=pq.top();
            pq.pop();
            if(first>second) pq.push(first-second);
        }
        if(pq.empty()) return 0;
        else return pq.top();
    }
};