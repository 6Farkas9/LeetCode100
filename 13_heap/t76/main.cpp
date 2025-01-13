#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

class MedianFinder {
public:
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(this->max_heap.empty()){
            this->max_heap.push(num);
        }
        else if(num > this->max_heap.top()){
            this->min_heap.push(num);
            if(this->min_heap.size() > this->max_heap.size()){
                this->max_heap.push(this->min_heap.top());
                this->min_heap.pop();
            }
        }
        else{
            this->max_heap.push(num);
            if(this->max_heap.size() > this->min_heap.size() + 1){
                this->min_heap.push(this->max_heap.top());
                this->max_heap.pop();
            }
        }
    }
    
    double findMedian() {
        if(this->max_heap.size() > this->min_heap.size())
            return this->max_heap.top();
        else
            return (double(this->max_heap.top()) + double(this->min_heap.top())) / 2.0;
            
    }
private:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
};

int main(){
    MedianFinder A;
    A.addNum(12);
    cout << A.findMedian() << endl;
    A.addNum(10);
    cout << A.findMedian() << endl;
    A.addNum(13);
    cout << A.findMedian() << endl;
    A.addNum(11);
    cout << A.findMedian() << endl;
    A.addNum(5);
    cout << A.findMedian() << endl;
    // 5 10 11 12 13
}

// class MedianFinder {
// public:
//     MedianFinder() {

//     }
    
//     void addNum(int num) {
//         if(this->max_heap.empty()){
//             insertMaxHeap(num);
//         }
//         else if(num <= this->max_heap[0]){
//             if(this->max_heap.size() > this->min_heap.size()){
//                 insertMinHeap(this->max_heap[0]);
//                 replaceMaxHeap(num);
//             }
//             else{
//                 insertMaxHeap(num);
//             }
//         }
//         else if(this->min_heap.empty()){
//             insertMinHeap(num);
//         }
//         else if(num >= this->min_heap[0]){
//             if(this->min_heap.size() > this->max_heap.size()){
//                 insertMaxHeap(this->min_heap[0]);
//                 replaceMinHeap(num);
//             }
//             else{
//                 insertMinHeap(num);
//             }
//         }
//         else{
//             if(this->min_heap.size() <= this->max_heap.size())   insertMinHeap(num);
//             else    insertMaxHeap(num);
//         }
//         // cout << "insert:" << num << endl;
//         // cout << "max heap:";
//         // for(int val : max_heap) cout << val << " ";
//         // cout << endl;
//         // cout << "min heap:";
//         // for(int val : min_heap) cout << val << " ";
//         // cout << endl;
//     }
    
//     double findMedian() {
//         int min_num = this->min_heap.size();
//         int max_num = this->max_heap.size();
//         if(min_num > max_num)   return double(this->min_heap[0]);
//         else if(min_num < max_num)  return double(this->max_heap[0]);
//         else    return (double(this->min_heap[0]) + double(this->max_heap[0])) / 2.0;
//     }
// private:
//     vector<int> min_heap; // 一半最大的，堆顶最小
//     vector<int> max_heap; // 一半最小的，堆顶最大
//     void insertMinHeap(int num){
//         this->min_heap.push_back(num);
//         int c_pos = this->min_heap.size() - 1;
//         int p_pos = c_pos % 2 == 1 ? c_pos / 2 : (c_pos - 1) / 2;
//         while(this->min_heap[c_pos] < this->min_heap[p_pos]){
//             swap(this->min_heap[c_pos], this->min_heap[p_pos]);
//             c_pos = p_pos;
//             p_pos = c_pos % 2 == 1 ? c_pos / 2 : (c_pos - 1) / 2;
//         }
//     }
//     void insertMaxHeap(int num){
//         this->max_heap.push_back(num);
//         int c_pos = this->max_heap.size() - 1;
//         int p_pos = c_pos % 2 == 1 ? c_pos / 2 : (c_pos - 1) / 2;
//         while(this->max_heap[c_pos] > this->max_heap[p_pos]){
//             swap(this->max_heap[c_pos], this->max_heap[p_pos]);
//             c_pos = p_pos;
//             p_pos = c_pos % 2 == 1 ? c_pos / 2 : (c_pos - 1) / 2;
//         }
//     }
//     void replaceMinHeap(int num){
//         if(this->min_heap.empty()){
//             this->min_heap.push_back(num);
//             return;
//         }
//         this->min_heap[0] = num;
//         int length = this->min_heap.size();
//         int c_pos = 0;
//         int c_left = c_pos * 2 + 1, c_right = c_pos * 2 + 2;
//         while(c_right < length && (this->min_heap[c_pos] > this->min_heap[c_left] || this->min_heap[c_pos] > this->min_heap[c_right])){
//             int next_pos = c_left;
//             if(this->min_heap[c_right] < this->min_heap[c_left])    next_pos = c_right;
//             swap(this->min_heap[c_pos], this->min_heap[next_pos]);
//             c_pos = next_pos;
//             c_left = c_pos * 2 + 1;
//             c_right = c_pos * 2 + 2;
//         }
//         if(c_left < length && this->min_heap[c_pos] > this->min_heap[c_left])
//             swap(this->min_heap[c_pos], this->min_heap[c_left]);
//     }
//     void replaceMaxHeap(int num){
//         if(this->max_heap.empty()){
//             this->max_heap.push_back(num);
//             return;
//         }
//         this->max_heap[0] = num;
//         int length = this->max_heap.size();
//         int c_pos = 0;
//         int c_left = c_pos * 2 + 1, c_right = c_pos * 2 + 2;
//         while(c_right < length && (this->max_heap[c_pos] < this->max_heap[c_left] || this->max_heap[c_pos] < this->max_heap[c_right])){
//             int next_pos = c_left;
//             if(this->max_heap[c_right] > this->max_heap[c_left])    next_pos = c_right;
//             swap(this->max_heap[c_pos], this->max_heap[next_pos]);
//             c_pos = next_pos;
//             c_left = c_pos * 2 + 1;
//             c_right = c_pos * 2 + 2;
//         }
//         if(c_left < length && this->max_heap[c_pos] < this->max_heap[c_left])
//             swap(this->max_heap[c_pos], this->max_heap[c_left]);
//     }
// };
