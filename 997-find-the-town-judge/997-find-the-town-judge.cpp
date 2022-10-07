class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size()==0){
            if(n==1) return 1;
            else return -1;
        }
        vector<int> people(n+1);
        for(auto &t: trust){
            people[t[1]]++;
            people[t[0]]--;
        }
        for(int i=0; i<n+1; i++) if(people[i]==n-1) return i;
        return -1;
    }
};