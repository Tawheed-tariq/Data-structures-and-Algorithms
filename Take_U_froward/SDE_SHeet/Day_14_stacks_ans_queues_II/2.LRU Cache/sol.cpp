class LRUCache {
    public:
        class Node{
            public:
                int key;
                int val;
                Node *next;
                Node *prev;
    
                Node(int key, int val){
                    this->key = key;
                    this->val = val;
                    this->next = NULL;
                    this->prev = NULL;
                }
        };
        int capacity;
        unordered_map<int, Node*> mp;
    
        Node *head = new Node(-1,-1);
        Node *tail = new Node(-1, -1);
    
        void deleteNode(Node *node){
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
    
        void insertAthead(Node *node){
            node->next = head->next;
            head->next = node;
            node->prev = head;
            node->next->prev = node;
        }
    
        LRUCache(int capacity) {
            this->capacity = capacity;
            head->next = tail;
            tail -> prev = head;
        }
        
        int get(int key) {
            if(mp.find(key) == mp.end())
                return -1;
            Node *curr = mp[key];
            deleteNode(curr);
            insertAthead(curr);
            return curr->val;
        }
        
        void put(int key, int value) {
            if(mp.find(key) != mp.end()){
                Node *curr = mp[key];
                curr->val = value;
                deleteNode(curr);
                insertAthead(curr);
                return;
            }
            Node *temp = new Node(key, value);
            if(mp.size() == capacity){
                //delete least recently used node
                Node *todel = tail->prev;
                deleteNode(todel);
                mp.erase(todel->key);
    
                //insert new entry
                insertAthead(temp);
                mp[key] = temp;
            }else{
                insertAthead(temp);
                mp[key] = temp;
            }
        }
    };
    
    /**
     * Your LRUCache object will be instantiated and called as such:
     * LRUCache* obj = new LRUCache(capacity);
     * int param_1 = obj->get(key);
     * obj->put(key,value);
     */