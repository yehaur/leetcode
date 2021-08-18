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
    void recVal(TreeNode* tr){
        if(!tr) return;
        recVal(tr->left);
        rec_val.push_back(tr->val);
        recVal(tr->right);
    }
    
    void swapVal(TreeNode* tr){
        if(!tr) return;
        swapVal(tr->left);
        tr->val = rec_val[ind++];
        swapVal(tr->right);
    }
    
    void recoverTree(TreeNode* root) {
        recVal(root);
        sort(rec_val.begin(), rec_val.end());
        swapVal(root);
    }
private:
    vector<int> rec_val;
    int ind = 0;
};
