class Solution {
public:
    int candy(vector<int>& ratings) {
        int size= ratings.size();
      
        if(size==1) return size;
      
        vector<int> l2r(size, 1), r2l(size, 1);
      
        for(int i=1; i<size; ++i){
          if(ratings[i]>ratings[i-1]) l2r[i]= l2r[i-1]+1;
        }
      
        for(int i=size-2; i>=0; --i){
          if(ratings[i]>ratings[i+1]) r2l[i]= r2l[i+1]+1;
        }
      
        int maxi= 0;
        
        for(int i=0; i<size; ++i) maxi+= max(l2r[i], r2l[i]);
      
        return maxi;
    }
};