class Solution {
public:
    int calc(const vector<vector<int>>& g, unordered_map<int, unordered_set<int>>& visit, int r, int c){
        if(r<0 || c<0 || r>=g.size() || c>=g[0].size()) return 0;
        if(visit.count(r) && visit[r].count(c)) return 0;
        if(!g[r][c]) return 0;
        
        visit[r].insert(c);
        return 1 + calc(g, visit, r-1, c) + calc(g, visit, r+1, c) +
                   calc(g, visit, r, c-1) + calc(g, visit, r, c+1);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(!grid.size() || !grid[0].size()) return 0;
        
        int ans = 0;
        unordered_map<int, unordered_set<int>> visit;
        int r=grid.size(), c=grid[0].size();
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j] && (!visit.count(i)||!visit[i].count(j))){
                    ans = max(ans, calc(grid, visit, i, j));
                }
            }
        }
        return ans;
    }
};
