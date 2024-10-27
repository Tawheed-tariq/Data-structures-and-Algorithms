class Twitter {
public:
    class Node{
        public:
            int usrId, twtId;
            Node *next, *prev;
            Node(int usrId, int twtId){
                this->usrId = usrId;
                this->twtId = twtId;
                next = NULL;
                prev = NULL;
            }
    };

    unordered_map<int, set<int>> mp; //for storing follower and folowee
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    Twitter() {
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
    
    void postTweet(int userId, int tweetId) {
        Node *temp = new Node(userId, tweetId);
        insertAtHead(temp);
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        Node *ptr = head->next;
        while(ptr && res.size() != 10){
            if(ptr->usrId == userId || mp[userId].find(ptr->usrId) != mp[userId].end())
                res.push_back(ptr->twtId);
            ptr= ptr->next;
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        mp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        mp[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */