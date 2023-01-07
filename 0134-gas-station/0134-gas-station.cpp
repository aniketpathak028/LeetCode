class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size= gas.size(), tot_cost= 0;
        vector<int> diff(size), val(size); 
        for(int i=0; i<size; ++i){
            diff[i]= gas[i]-cost[i];
            tot_cost+= diff[i];
        }
        if(tot_cost<0) return -1;
        val[size-1]= diff[size-1];
        for(int i=size-2; i>=0; --i){
            val[i]= val[i+1]+diff[i];
        }
        int idx, maxi= INT_MIN;
        for(int i=0; i<size; ++i){
            if(val[i]>maxi){
                idx= i;
                maxi= val[i];
            }
        }
        return idx;
    }
    // i: 0 1 2 3 4 
    // g: 1 2 3 4 5
    // c: 3 4 5 1 2
    // d: -2 -2 -2 3 3
    
    // i: 0 1 2
    // g: 2 3 4
    // c: 3 4 3
    // d: -1 1 -1
};