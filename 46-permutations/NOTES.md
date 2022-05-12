void findPermute(vector<int>& nums, vector<vector<int>> &ans, int index){
if(index==nums.size()){
ans.push_back(nums);
return;
}
for(int i=index; i<=nums.size()-1; i++){
swap(nums[index], nums[i]);
findPermute(nums, ans, index+1);
swap(nums[index], nums[i]);
}
}
vector<vector<int>> permute(vector<int>& nums) {
vector<vector<int>> ans;
findPermute(nums, ans, 0);
return ans;
}