class Solution {
private:
    typedef pair<int, int> P;
public:
    struct comp{
        bool operator()(const P& p1, const P& p2){
            if(p1.first > p2.first) return true;
            if(p1.first < p2.first) return false;
            return p1.second > p2.second;
        }
    };
    
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n=servers.size(), m=tasks.size(), task=0, cnt=0;
        priority_queue<P, vector<P>, comp> pq, busy_pq;
        for(int i=0; i<n; i++) pq.push(make_pair(servers[i], i));
        vector<int> ans;
        
        while(task < m){
            if(pq.empty())
                cnt = busy_pq.top().first;
            while(!busy_pq.empty() && busy_pq.top().first<=cnt){
                auto b = busy_pq.top(); busy_pq.pop();
                b.first = servers[b.second];
                pq.push(b);
            }
            
            auto a = pq.top(); pq.pop();
            a.first = cnt + tasks[task];
            ans.push_back(a.second);
            busy_pq.push(a);
            cnt = max(cnt,++task);
        }
        return ans;
    }
};
