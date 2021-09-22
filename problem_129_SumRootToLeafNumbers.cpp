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
    void myfunc(TreeNode* t,int& ans,string s)
    {
        if(!t)
            return;
        s+=to_string(t->val);
        if(!t->left && !t->right)
            ans+=stoi(s);
        myfunc(t->left,ans,s);
        myfunc(t->right,ans,s);
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        myfunc(root,ans,"");
        return ans;
    }
};
