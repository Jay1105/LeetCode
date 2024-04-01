class LRUCache {
public:
    class Node 
    {
    public:
        int key, val;
        Node* prev;
        Node* next;
        
        Node(int key, int val) {
            this->key = key;
            this->val = val;
        }
    };
    
    int cap;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> mp;
    
    LRUCache(int capacity) 
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node* newNode)
    {
        Node* temp = head->next;

        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }
    
    void deleteNode(Node* delNode)
    {
        Node* prevNode = delNode->prev;
        Node* nextNode = delNode->next;
        
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    
    int get(int key) 
    {
        if (mp.find(key) != mp.end())
        {
            Node* curr = mp[key];
            int ans = curr->val;
            
            mp.erase(key);
            deleteNode(curr);
            addNode(curr);

            mp[key] = head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) 
    {
        if (mp.find(key) != mp.end())
        {
            Node* curr = mp[key];
            mp.erase(key);
            deleteNode(curr);
        }

        if (mp.size() == cap)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        Node* newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */