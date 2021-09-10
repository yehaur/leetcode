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
        if(!root) return NULL;
        
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int qsize = q.size();
            for(int i=0; i<qsize; i++){
                Node* nd = q.front();
                if(nd->left) { // Assume every parent has two children or 0
                    q.push(q.front()->left);
                    q.push(q.front()->right);
                }
                q.pop();
                if(i != qsize-1) nd->next = q.front();
                else  nd->next = NULL;
            }
        }
        return root;
    }
};
