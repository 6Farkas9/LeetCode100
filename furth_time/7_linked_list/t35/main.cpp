#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        _data = new DataNode;
        _data->last = _data;
        _data->next = _data;
        _capacity = capacity;
    }
    
    int get(int key) {
        if(_val2node.find(key) == _val2node.end()) {
            return -1;
        }
        DataNode *p = _val2node[key];
        moveToHead(p);
        return p->val;
    }
    
    void put(int key, int value) {
        if(_val2node.find(key) != _val2node.end()) {
            DataNode *p = _val2node[key];
            p->val = value;
            moveToHead(p);
        }
        else {
            DataNode *p = new DataNode(key, value, _data, _data->next);
            _data->next->last = p;
            _data->next = p;
            _val2node[key] = p;
            --_capacity;
            if(_capacity < 0) {
                DataNode *todelete = _data->last;
                todelete->last->next = todelete->next;
                todelete->next->last = todelete->last;
                _val2node.erase(todelete->key);
                delete todelete;
                ++_capacity;
            }
        }
    }
private:
    struct DataNode {
        int key;
        int val;
        DataNode *last, *next;
        DataNode() {};
        DataNode(int _key, int _val) : key(_key), val(_val) {};
        DataNode(int _key, int _val, DataNode* _last, DataNode* _next) : key(_key), val(_val), last(_last), next(_next) {}
    };
    DataNode *_data;
    unordered_map<int, DataNode*> _val2node;
    int _count;
    int _capacity;

    void moveToHead(DataNode* &p) {
        if(_data->next == p)    return;
        p->last->next = p->next;
        p->next->last = p->last;

        p->next = _data->next;
        p->last = _data;

        _data->next->last = p;
        _data->next = p;
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