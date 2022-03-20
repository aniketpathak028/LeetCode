class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double sum=0;
        for(auto it: nums){
            pq.push(it);
            sum+=it;
        }
        double half= sum/2;
        int ans=0;
        while(sum>half){
            ans++;
            double top = pq.top();
            pq.pop();
            top = top/2;
            sum-=top;
            pq.push(top);
        }
        return ans;
    }
};