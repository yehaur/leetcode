// Use queue(BFS)

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if(s.back() == '1') return false;

        int n = s.size();
        queue<int> q; q.push(0);
        unordered_set<int> visited; visited.insert(0);

        for(int i=1; i<n; i++){
            if(s[i] == '1') continue;

            int diff;
            while(!q.empty()){
                diff = i - q.front();
                if(diff <= maxJump) break;
                q.pop();
            }

            if(!q.empty() && diff>=minJump){
                visited.insert(i);
                q.push(i);
            }
        }
        return visited.count(n-1);
    }
};
