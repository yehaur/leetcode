class Solution {
public:
    bool dfs(int from, vector<int>& v, vector<vector<int>>& graph){
        for(int ind:graph[from]){
            if(v[ind] == -1){
                v[ind] = 1-v[from];
                if(!dfs(ind, v, graph)) return false;
            }else if(v[ind] == v[from]) return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> visit(graph.size(), -1);
        for(int i=0 ;i<graph.size(); i++){
            if(visit[i] == -1){
                visit[i] = 1;
                if(!dfs(i, visit, graph)) return false;
            }
        }
        return true;
    }
};
