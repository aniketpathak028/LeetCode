class Solution {
public:
    int dp[1001][1001];
    int sfx[1001];
    void findSuffix(string &floor){
        int n= floor.size();
        sfx[n-1]= (floor[n-1]=='1');
        for(int i=n-2; i>=0; i--) sfx[i]= sfx[i+1] + (floor[i]=='1');
    }
    int solve(string &floor, int numCarpets, int carpetLen, int i, int used){
        if(used==numCarpets | i>=floor.size()) return i>=floor.size() ? 0 : sfx[i];
        if(dp[i][used]!=-1) return dp[i][used];
        return dp[i][used]= min(solve(floor, numCarpets, carpetLen, i+carpetLen, used+1), (floor[i]=='1')+solve(floor, numCarpets, carpetLen, i+1, used));
    }
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        memset(dp, -1, sizeof(dp));
        findSuffix(floor);
        return solve(floor, numCarpets, carpetLen, 0, 0);
    }
};