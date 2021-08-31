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
    void flatten(TreeNode* root) {
        if(!root) return;
        if(!root->left && !root->right) return;
        
        flatten(root->left);
        if(root->left){
            TreeNode* l = new TreeNode();
            l = root->left;
            root->left = NULL;
            TreeNode* tmp = l;
            while(tmp->right) tmp = tmp->right;
            flatten(root->right);
            tmp->right = root->right; 
            root->right = l;
        }else
            flatten(root->right);
    }
};
