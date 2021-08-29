/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    int lenNode(ListNode* ln){
        int h = 0;
        ListNode* tnd = new ListNode();
        tnd = ln;
        while(tnd){
            h++;
            tnd = tnd->next;
        }
        return h;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        if(!head->next){
            TreeNode* tn = new TreeNode(head->val);
            return tn;
        }
        
        ListNode* lroot = new ListNode(); lroot = head;
        ListNode* root = new ListNode(); root = head->next;
        ListNode* rroot = new ListNode(); rroot = head->next->next;

        int m=1, h = lenNode(head);
        while(m < h/2){
            rroot = rroot->next;
            root = root->next;
            lroot = lroot->next;
            m++;
        }
        
        ListNode* ltmp = head;
        while(ltmp && ltmp!=lroot) ltmp = ltmp->next;
        ltmp->next = NULL;
        
        TreeNode* tnm = new TreeNode(root->val);
        tnm->left = sortedListToBST(head);
        tnm->right = sortedListToBST(rroot);
        return tnm;
    }
};
