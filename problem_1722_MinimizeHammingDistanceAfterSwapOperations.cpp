// from https://zxi.mytechroad.com/blog/uncategorized/leetcode-1722-minimize-hamming-distance-after-swap-operations/
//Think each pair as an edge in a graph. Since we can swap as many time as we want, which means we can arrange the elements whose indices are in a connected component (CC) in any order.
//For each index i, we increase the counter of CC(i) for key source[i] and decrease the counter of the same CC for key target[i]. If two keys are the same (can from different indices), one from source and one from target, it will cancel out, no distance. Otherwise, the counter will be off by two. Finally we sum up the counter for all the keys and divide it by two to get the hamming distance.

//Time complexity: O(V+E)
//Space complexity: O(V)

class Solution {
public:
  int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
    const int n = source.size();
    vector<int> p(n);
    iota(begin(p), end(p), 0);

    function<int(int)> find = [&](int x) {
      return x == p[x] ? x : p[x] = find(p[x]);
    };

    for (const auto& s : allowedSwaps)
      p[find(s[0])] = find(s[1]);

    unordered_map<int, unordered_map<int, int>> m;
    for (int i = 0; i < n; ++i) {
      ++m[find(i)][source[i]];
      --m[find(i)][target[i]];
    }

    int ans = 0;
    for (const auto& g : m)
      for (const auto& kv : g.second)
        ans += abs(kv.second);
    return ans / 2;
  }
};
