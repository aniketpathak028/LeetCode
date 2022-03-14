class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int least_price = INT_MAX;
        int max_profit = 0;
        int curr_profit = 0;
        
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < least_price)
                least_price = prices[i];
            curr_profit = prices[i] - least_price;
            if(curr_profit>max_profit) max_profit = curr_profit;
        }
        return max_profit;
    }
};