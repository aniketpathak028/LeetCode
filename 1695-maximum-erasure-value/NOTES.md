* Problem similar to Longest Substring Without Repeating Characters
* Use 2-pointer approach
​
```
int maximumUniqueSubarray(vector<int>& nums) {
int left= 0, right= 0, n= nums.size();
int max_sum= INT_MIN;
// two pointer algorithm to find the maximum sum subarray containing non-duplicate elements
vector<int> mp(1e4+1, -1); // map to store an element's last seen position
// find prefix sum
vector<int> prefix(n, 0);
int sum= 0;
for(int i=0; i<n; ++i){
sum+= nums[i];
prefix[i]= sum;
}
while(left<n && right<n){
// if a duplicate is found, move the left pointer to the right of its last occurence
if(mp[nums[right]]!=-1 && mp[nums[right]]>=left) left= mp[nums[right]]+1;
mp[nums[right]]= right; // update the new position of the element
// calculate the new maximum sum
max_sum= max(max_sum, prefix[right]-prefix[left]+nums[left]);
right++; // increment thr right pointer
}
return max_sum;
}
```