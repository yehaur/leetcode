class Solution {
public:
    struct comp{
        const bool operator()(const pair<int,int>& a, const pair<int,int>& b){
            return a.first>b.first ||
                   (a.first==b.first && a.second>b.second); 
        }
    };
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq;
        for(int a:arr){
            pair<int,int> p(std::abs(a-x), a);
            pq.push(p);
        }
        vector<int> ans;
        while(ans.size()<k && !pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
