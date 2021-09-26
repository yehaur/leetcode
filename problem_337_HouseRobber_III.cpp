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
    /*void record(TreeNode* tn, unordered_map<TreeNode*, int>& m){
        if(!tn) return;
        m[tn] = 0;
        record(tn->left, m);
        record(tn->right, m);
    }
    
    int calc(unordered_map<TreeNode*, int>& m, TreeNode* tn){
        if(!tn) return 0;
        if(m[tn] == 1) {
            if(tn->left) m[tn->left] = -1;
            if(tn->right) m[tn->right] = -1;
            return tn->val + calc(m, tn->left)+calc(m, tn->right);
        }
        
        if(m[tn] == -1) {
            int l(0), r(0);
            if(tn->left){
                m[tn->left] = 1;
                int tmpl1 = calc(m, tn->left);
                m[tn->left] = -1;
                int tmpl2 = calc(m, tn->left);
                if(tmpl1 >= tmpl2){
                    m[tn->left] = 1;
                    l = tmpl1;    
                }else{
                    m[tn->left] = -1;
                    l = tmpl2;    
                }
            }
            
            if(tn->right){
                m[tn->right] = 1;
                int tmpr1 = calc(m, tn->right);
                m[tn->right] = -1;
                int tmpr2 = calc(m, tn->right);
                if(tmpr1 >= tmpr2){
                    m[tn->right] = 1;
                    r = tmpr1;    
                }else{
                    m[tn->right] = -1;
                    r = tmpr2;    
                }
            }
            return l+r;
        }
        
        m[tn] = 1;
        int res1 = calc(m, tn);
        m[tn] = -1;
        int res2 = calc(m, tn);
        if(res1 >= res2) m[tn] = 1;
        else m[tn] = -1;
        return max(res1, res2);
    }
    */
    vector<int> calc(TreeNode* root){
        if(!root) return {0, 0};
        vector<int> l = calc(root->left);
        vector<int> r = calc(root->right);
        int rob_root = root->val + l[1] + r[1];
        int not_rob_root = max(l[0], l[1])+max(r[0], r[1]);
        return {rob_root, not_rob_root};
    }
    int rob(TreeNode* root) {
        if(!root) return 0;
        auto ans = calc(root);
        return max(ans[0], ans[1]);
        /*unordered_map<TreeNode*, int> m;
        record(root, m);
        return calc(m, root);*/
    }
};
