// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

// Implement the LRUCache class:

//     LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
//     int get(int key) Return the value of the key if the key exists, otherwise return -1.
//     void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.

// The functions get and put must each run in O(1) average time complexity.

class LRUCache {
public:
    class Node{
        public:
            int key, value;
            Node* next, *prev;
            Node(int key, int value){
                this->key = key;
                this->value = value;
                next = NULL;
                prev = NULL;
            }
    };

    int capacity;
    unordered_map<int, Node*>mp;

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAtHead(Node* node){
        Node* temp = head->next;
        head->next = node;
        node->prev = head; 

        node->next = temp;
        temp->prev = node;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        else{
            Node* currNode = mp[key];
            deleteNode(currNode);
            insertAtHead(currNode); //this key-value pair is used hence added at start of cache
            return currNode->value;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* currNode = mp[key];
            currNode->value = value; 
            deleteNode(currNode);
            insertAtHead(currNode); //after updating the value put at front
        }
        else{
            Node* newNode = new Node(key, value);
            if(mp.size() == capacity){
                Node* todel = tail->prev;
                mp.erase(todel->key); //least recently used == tail->prev
                deleteNode(tail->prev);
                insertAtHead(newNode);
                mp[key]  = newNode;
                delete todel;
            }
            else{
                insertAtHead(newNode);
                mp[key] = newNode;
            }
        }
    }
};
