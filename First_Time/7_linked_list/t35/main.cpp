#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->head = (Data_List*)malloc(sizeof(Data_List));
        this->head->next = NULL;
        this->head->last = NULL;
    }
    
    int get(int key) {
        if(this->data.find(key) != this->data.end()){
            Data_List *temp = this->data[key];
            moveToHead(temp);
            return temp->value;
        } 
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        Data_List *temp;
        if(this->data.find(key) != this->data.end()){
            temp = this->data[key];
            temp->value = value;
            moveToHead(temp);
        }
        else if(this->capacity){
            temp = (Data_List*)malloc(sizeof(Data_List));
            temp->value = value;
            temp->key = key;
            this->data[key] = temp;
            if(head->next == NULL){
                head->next = temp;
                temp->next = head;
                head->last = temp;
                temp->last = head;
            }
            else{
                temp->next = head->next;
                temp->last = head;
                head->next->last = temp;
                head->next = temp;
            }
            this->capacity--;
        }
        else{
            Data_List *todelete = head->last;
            data.erase(todelete->key);
            data[key] = todelete;
            todelete->value = value;
            todelete->key = key;
            moveToHead(todelete);
        }
    }
private:
    int capacity;
    struct Data_List {
        int value;
        int key;
        struct Data_List *last;
        struct Data_List *next;
        Data_List() : value(0), key(0), next(nullptr), last(nullptr) {}
    };
    unordered_map<int, Data_List*> data;
    Data_List *head;

    void moveToHead(Data_List *ptr){
        if(ptr->last == this->head){
            return;
        }
        else{
            ptr->last->next = ptr->next;
            ptr->next->last = ptr->last;
            ptr->next = this->head->next;
            ptr->last = this->head;
            this->head->next->last = ptr;
            this->head->next = ptr;
        }
    }
};

int main(){
    LRUCache A(2);
    cout << A.get(2) << endl;
    A.put(2,6);

    cout << A.get(1) << endl;
    A.put(1,5);

    A.put(1,2);

    cout << A.get(1) << endl;
    cout << A.get(2) << endl;
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */