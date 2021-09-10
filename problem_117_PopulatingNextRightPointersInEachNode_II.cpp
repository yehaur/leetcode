/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q; q.push(root);
        while(!q.empty()){
            int qsz = q.size();
            for(int i=0; i<qsz;){
                Node* nd = q.front(); q.pop(); i++;
                if(!nd) continue;
                
                while(i<qsz && !q.front()) {i++; q.pop();}
                if(i == qsz)
                    nd->next = NULL;
                else {
                    nd->next = q.front();
                }
                if(nd->left) q.push(nd->left); else q.push(NULL);
                if(nd->right) q.push(nd->right); else q.push(NULL);
            }
        }
        return root;
    }
};
