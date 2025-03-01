#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity){
        this->_capacity = capacity;
        this->_head = new DataNode();
        this->_head->last = this->_head->next = this->_head;
    }
    
    int get(int key) {
        if(this->_key_to_data.find(key) != this->_key_to_data.end()){
            DataNode *node = this->_key_to_data[key];
            moveToHead(node);
            return node->value;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(this->_key_to_data.find(key) != this->_key_to_data.end()){
            DataNode *node = this->_key_to_data[key];
            node->value = value;
            moveToHead(node);
        }
        else{
            if(this->_capacity){
                DataNode *node = new DataNode(key, value, this->_head, this->_head->next);
                this->_head->next->last = node;
                this->_head->next = node;
                this->_key_to_data[key] = node;
                --this->_capacity;
            }
            else{
                DataNode *dnode = this->_head->last;
                this->_key_to_data.erase(dnode->key);
                dnode->key = key;
                dnode->value = value;
                this->_key_to_data[key] = dnode;
                moveToHead(dnode);
            }
        }
    }
private:
    int _capacity;
    struct DataNode {
        int key, value;
        struct DataNode *last, *next;
        DataNode() : key(0), value(0), last(nullptr), next(nullptr) {}
        DataNode(int key, int value) : key(key), value(value), last(nullptr), next(nullptr) {}
        DataNode(int key, int value, DataNode* last, DataNode* next) : key(key), value(value), last(last), next(next) {}
    };
    unordered_map<int, DataNode*> _key_to_data;
    DataNode *_head;

    void moveToHead(DataNode* &node){
        node->last->next = node->next;
        node->next->last = node->last;
        node->last = this->_head;
        node->next = this->_head->next;
        this->_head->next->last = node;
        this->_head->next = node;
    }
};

int main(){
    LRUCache A(2);
    cout << A.get(2) << endl;
    A.put(2,6);

    cout << A.get(1) << endl;
    A.put(1,5);

    A.put(1,2);

    A.put(3,10);

    cout << A.get(1) << endl;
    cout << A.get(2) << endl;
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */