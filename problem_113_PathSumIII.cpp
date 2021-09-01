/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void calc(TreeNode* nd, vector<int>& v, int target, vector<vector<int>>& ans){
        if(!nd) return;
        if(!nd->left && !nd->right) {
            if(nd->val == target){
                v.push_back(nd->val);
                ans.push_back(v);
            }
            return;
        }
        
        v.push_back(nd->val);
        int vs = v.size();
        calc(nd->left, v, target - nd->val, ans);
        v.resize(vs);
        calc(nd->right, v, target - nd->val, ans);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(!root) return ans;
        
        vector<int> tmp;
        calc(root, tmp, targetSum, ans);
        return ans;
    }
};
