class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto &it: nums) s.insert(it);
        int len= 0;
        for(auto &num: nums){
          if(s.find(num-1)==s.end()){
            int c= num+1;
            while(s.find(c)!=s.end()) c++;
            len= max(len, c-num);
          }
        }
      return len;
    }
};