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
class Solution {
public:
    int lenList(ListNode* ln){
        if(!ln) return 0;
        return 1+lenList(ln->next);
    }
    
    void move(ListNode* ln1, int pos1, int& des1, 
              ListNode* ln2, int pos2, int& des2){
        if(pos1==des1 && pos2==des2) swap(ln1, ln2);
        
        if(pos1 < des1) {
            ln1 = ln1->next;
            move(ln1, pos1+1, des1, ln2, pos2, des2);
        }if(pos2 < des1) {
            ln2 = ln2->next;
            move(ln1, pos1, des1, ln2, pos2+1, des2);
        }
    }
    
    ListNode* swapNodes(ListNode* head, int k) {
        int n = lenList(head), target1=k, target2=n-k+1;
        if(target1 == target2) return head;
        
        ListNode* p1 = head, *p2 = head;
        int move = 1;
        while(move < target1){
            p1 = p1->next;
            move++;
        }
        move = 1;
        while(move < target2){
            p2 = p2->next;
            move++;
        }
        
        ListNode* tmp1 = p1->next;
        ListNode* tmp2 = p2->next;
        int tmp = p1->val;
        p1->val = p2->val;
        p2->val = tmp;
        return head;
    }
};
