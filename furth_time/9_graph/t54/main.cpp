#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

class Trie {
public:
    Trie() {
        _head = new DataNode;
    }
    
    void insert(string word) {
        int length = word.size() - 1, i;
        DataNode* p = _head;
        for(i = 0; i < length; ++i) {
            if(p->data.find(word[i]) == p->data.end()) {
                p->data[word[i]] = make_pair(false, new DataNode);
            }
            p = p->data[word[i]].second;
        }
        if(p->data.find(word[length]) == p->data.end()) {
            p->data[word[length]] = make_pair(true, new DataNode);
        }
        else {
            p->data[word[length]].first = true;
        }
    }
    
    bool search(string word) {
        int length = word.size() - 1;
        DataNode* p = _head;
        for(int i = 0; i < length; ++i) {
            if(p->data.find(word[i]) == p->data.end())  return false;
            p = p->data[word[i]].second;
        }
        if(p->data.find(word[length]) == p->data.end() || !p->data[word[length]].first)
            return false;
        return true;
    }
    
    bool startsWith(string prefix) {
        int length = prefix.size();
        DataNode* p = _head;
        for(int i = 0; i < length; ++i) {
            if(p->data.find(prefix[i]) == p->data.end())
                return false;
            p = p->data[prefix[i]].second;
        }
        return true;
    }
private:
    struct DataNode {
        unordered_map<char, pair<bool, DataNode*>> data;
    };
    DataNode *_head;
};

int main(){
    // Solution A;
    // cout << A.canFinish(grid) << endl;;
}