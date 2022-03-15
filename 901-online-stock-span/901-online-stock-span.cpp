class StockSpanner {
public:
    StockSpanner() {
        
    }
    stack<int> st;
    vector<int> NGL;
    vector<int> prices;
    int i=0;
    int next(int price) {
        prices.push_back(price);
           if(st.empty()) NGL.push_back(1+i);
           else if(prices[st.top()]>prices[i]) NGL.push_back(i-st.top());
           else if(prices[st.top()]<=prices[i]){
               while(!st.empty() && prices[st.top()]<=prices[i]) st.pop();
               if(st.empty()) NGL.push_back(1+i);
               else NGL.push_back(i-st.top());
           }
            st.push(i);
            return NGL[i++];
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */