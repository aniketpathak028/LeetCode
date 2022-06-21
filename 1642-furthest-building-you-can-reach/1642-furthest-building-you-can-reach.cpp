class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>> min_heap;
        int n= heights.size();
        vector<int> diff(n-1);
        for(int i=0; i<n-1; ++i){
          diff[i]= heights[i+1]-heights[i];
        }
        
        int bricks_left= bricks;
        for(int i=0; i<diff.size(); ++i){
          int h= diff[i];
          if(h>0){
            min_heap.push(h);
            if(min_heap.size()>ladders){
              int add= min_heap.top();
              min_heap.pop();
              if(add<=bricks_left) bricks_left-= add;
              else return i;
            }
          }
        }
      return heights.size()-1;
    }
};