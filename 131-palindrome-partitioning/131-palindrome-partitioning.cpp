class Solution {
public:
    bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
    void createPartitions(string s, vector<vector<string>> &res, vector<string> &ds, int index){
        if(index==s.size()){
            res.push_back(ds);
            return;
        }
        
        for(int i=index; i<s.size(); i++){
            if(isPalindrome(s, index, i)){
                ds.push_back(s.substr(index, i - index + 1));
                createPartitions(s, res, ds, i+1);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> ds;
        createPartitions(s, res, ds, 0);
        return res;
    }
};