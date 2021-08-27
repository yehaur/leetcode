class LRUCache {
    struct Node{
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int _key, int _val):key(_key), val(_val){};
        Node(int _key, int _val, Node* p):key(_key), val(_val), prev(p){};
        Node(int _key, int _val, Node* p, Node* n):key(_key), val(_val), prev(p), next(n){};
    };

public:
    void addnode(Node* n){
        Node* tmp = head->next;
        n->prev = head;
        n->next = tmp;
        head->next = n;
        tmp->prev = n;
    }
    
    void delnode(Node* n){
        Node* p = n->prev;
        Node* l = n->next;
        p->next = l;
        l->prev = p;
    }
    
    LRUCache(int capacity) {
        Cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(rec.count(key)) {
            Node* n = rec[key];
            int res = n->val;
            rec.erase(key);
            delnode(n);
            addnode(n);
            rec[key] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(rec.count(key)){
            Node* n = rec[key];
            rec.erase(key);
            delnode(n);
        }
        
        if(rec.size() == Cap){
            rec.erase(tail->prev->key);
            delnode(tail->prev);
        }
        
        addnode(new Node(key, value));
        rec[key] = head->next;
    }

private:
    int Cap;
    unordered_map<int, Node*> rec;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
