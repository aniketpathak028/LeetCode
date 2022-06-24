bool isPossible(vector<int>& target) {
priority_queue<int> max_heap(target.begin(), target.end()); // initialize max heap
long sum= accumulate(target.begin(), target.end(), 0); // total sum
while(true){
int top= max_heap.top(); max_heap.pop(); // find top and pop
sum-= top; // substract top from sum to find sum of remaining elements
// if top=1, all elements have become 1's
// if sum=1, sum of remaining elements is 1 and hence return true
if(top==1 || sum==1) return true;
// if sum=0, 1 element was present only
// if top<sum, difference will be negative
// if top is a multiple of sum, the target can never be achieved
if(sum==0 || top<sum || top%sum==0) return false;
top= top%sum; // reduce top as many times possible
sum+= top; // add the new element to sum
max_heap.push(top); // add new element to heap
}
}