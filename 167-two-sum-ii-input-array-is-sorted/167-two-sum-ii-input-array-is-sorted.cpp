class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        for(int i=0; i<numbers.size(); ++i){
          int num1= numbers[i];
          int num2= target-num1;
          if(binary_search(numbers.begin()+i+1, numbers.end(), num2)){
            ans.push_back(i+1);
            int pos2= lower_bound(numbers.begin()+i+1, numbers.end(), num2)-numbers.begin()+1;
            ans.push_back(pos2);
            break;
          }
        }
      return ans;
    }
};