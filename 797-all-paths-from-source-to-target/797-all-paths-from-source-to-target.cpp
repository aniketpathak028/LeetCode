class Solution {
public:
    void dfs(int start, int end, vector<int> &path, vector<vector<int>> &ans, vector<vector<int>> &graph){
        if(start==end){
            path.push_back(end);
            ans.push_back(path);
            path.pop_back();
        }
        
        path.push_back(start);
        for(auto &node: graph[start]){
            dfs(node, end, path, ans, graph);
        }
        path.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(0, graph.size()-1, path, ans, graph);
        return ans;
    }
};