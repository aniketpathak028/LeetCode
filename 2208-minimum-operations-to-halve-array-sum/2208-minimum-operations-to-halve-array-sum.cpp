class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        for(auto it: nums) pq.push(it);
        double sum = 0;
        for(auto it: nums) sum+=it;
        double half = sum/2;
        int ans=0;
        while(sum>half){
            ans++;
            double maxi= pq.top();
            sum-=maxi/2;
            pq.pop();
            pq.push(maxi/2);
        }
        return ans;
    }
};