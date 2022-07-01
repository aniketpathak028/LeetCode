class Solution {
public:
    static bool cmp(vector<int> v1, vector<int> v2){
      return v1[1]>v2[1];    
    }
  
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int maxi= 0, ts= truckSize;
        for(int i=0; i<boxTypes.size(); ++i){
          int size= boxTypes[i][0], units= boxTypes[i][1];
          if(ts==0) break;
          if(ts>=size){
            maxi+= size*units;
            ts-= size;
          }else{
            maxi+= ts*units;
            ts= 0;
          }
        }
      return maxi;
    }
};