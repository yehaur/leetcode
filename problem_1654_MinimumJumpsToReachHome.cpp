// BFS solution 
// Check previous step, and use 0,1 to indicate step backward and froward respectively
class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        if(!x) return 0;
        int ans = 0;
        unordered_set<int> us(forbidden.begin(), forbidden.end());
        queue<pair<int, int>> q;
        q.push({0,0});
        while(!q.empty()){
            int n = q.size();
            while(n--){
                auto cur = q.front(); q.pop();
                int num = cur.first;
                
                if(num == x) return ans;
                
                if(us.count(num)) continue;
                
                us.insert(num);
                if(!cur.second && num-b>=0){
                    q.push({num-b, 1});
                }
                
                if(num-b<=2001)
                    q.push({num+a, 0});
            }
            ans++;
        }
        return -1;
    }
};
