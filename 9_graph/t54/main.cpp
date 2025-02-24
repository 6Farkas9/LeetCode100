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
        this->head = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *p = this->head;
        int length = word.size(), i;
        for(i = 0; i < length; ++i){
            char ch = word[i];
            if(p->data.find(ch) == p->data.end())  break;
            p = p->data[ch];
        }
        for(; i < length; ++i){
            char ch = word[i];
            p->data[ch] = new TrieNode();
            p = p->data[ch];
        }
        p->isend = true;
    }
    
    bool search(string word) {
        TrieNode *p = this->head;
        int length = word.size();
        for(int i = 0; i < length; ++i){
            char ch = word[i];
            if(p->data.find(ch) == p->data.end())  return false;
            p = p->data[ch];
        }
        return p->isend;
    }
    
    bool startsWith(string prefix) {
        TrieNode *p = this->head;
        int length = prefix.size();
        for(int i = 0; i < length; ++i){
            char ch = prefix[i];
            if(p->data.find(ch) == p->data.end())  return false;
            p = p->data[ch];
        }
        return true;
    }
private:
    struct TrieNode{
        unordered_map<char,TrieNode*> data;
        bool isend;
        TrieNode(): isend(false){};
    };
    TrieNode *head;
};

int main(){
    // Solution A;
    // cout << A.canFinish(grid) << endl;;
}