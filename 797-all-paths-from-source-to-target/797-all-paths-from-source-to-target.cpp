class Solution {
public:
    void dfs(int start, int end, vector<int> path, vector<vector<int>> &ans, vector<vector<int>> &graph){
        if(start==end){
            path.push_back(end);
            ans.push_back(path);
        }
        
        path.push_back(start);
        for(auto &node: graph[start]){
            dfs(node, end, path, ans, graph);
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(0, graph.size()-1, path, ans, graph);
        return ans;
    }
};