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
        this->head = new TreeNode;
        this->head->is_tail = false;
    }
    
    void insert(string word) {
        int length = word.size();
        int i = 0;
        TreeNode *ptr = this->head;
        while(ptr->next.find(word[i]) != ptr->next.end() && i < length){
            ptr = ptr->next[word[i++]];
        }
        while(i < length){
            TreeNode *temp = new TreeNode;
            temp->is_tail = false;
            ptr->next[word[i]] = temp;
            ptr = ptr->next[word[i++]];
        }
        ptr->is_tail = true;
    }
    
    bool search(string word) {
        int length = word.size();
        int i = 0;
        TreeNode *ptr = this->head;
        while(ptr->next.find(word[i]) != ptr->next.end() && i < length){
            ptr = ptr->next[word[i++]];
        }
        if(i == length && ptr->is_tail) return true;
        else return false;
    }
    
    bool startsWith(string prefix) {
        int length = prefix.size();
        int i = 0;
        TreeNode *ptr = this->head;
        while(ptr->next.find(prefix[i]) != ptr->next.end() && i < length){
            ptr = ptr->next[prefix[i++]];
        }
        if(i == length) return true;
        else return false;
    }
private:
    typedef struct TreeNode{
        unordered_map<char,TreeNode*> next;
        bool is_tail;
    }TreeNode;
    TreeNode* head;
};

int main(){
    // Solution A;
    // cout << A.canFinish(grid) << endl;;
}