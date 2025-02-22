#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

vector<int> nums1 = {1,3};
vector<int> nums2 = {2};

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int length1 = nums1.size(), length2 = nums2.size();
        int k1 = (length1 + length2 + 1) / 2, k2 = (length1 + length2) / 2 + 1;
        int i1 = 0, i2 = 0, j1 = length1 - 1, j2 = length2 - 1;
        int mid1, mid2;
        double ans_k1, ans_k2;
        cout << k1 << "," << k2 << endl;
        while(true){
            if(i1 > j1) return (double(nums2[i2 + k1 - 1]) + double(nums2[i2 + k2 - 1])) / 2.0;
            if(i2 > j2) return (double(nums1[i1 + k1 - 1]) + double(nums1[i1 + k2 - 1])) / 2.0;
            if(k1 == 1){
                ans_k1 = min(nums1[i1], nums2[i2]);
                if(k2 == 1){
                    ans_k2 = ans_k1;
                    break;
                } 
                else{
                    if(nums1[i1] < nums2[i2])   i1++;
                    else i2++;
                    if(i1 <= j1 && i2 <= j2) ans_k2 = min(nums1[i1], nums2[i2]);
                    else if(i1 <= j1)   ans_k2 = nums1[i1];
                    else ans_k2 = nums2[i2];
                    break;
                }
            }
            mid1 = min((i1 + j1) / 2, i1 + k1 / 2 - 1);
            mid2 = min((i2 + j2) / 2, i2 + k2 / 2 - 1);
            if(nums1[mid1] < nums2[mid2]){
                k1 = k1 - (mid1 - i1 + 1);
                k2 = k2 - (mid1 - i1 + 1);
                i1 = mid1 + 1;
            }
            else{
                k1 = k1 - (mid2 - i2 + 1);
                k2 = k2 - (mid2 - i2 + 1);
                i2 = mid2 + 1;
            }
        }
        return (ans_k1 + ans_k2) / 2;
    }
};

int main(){
    Solution A;
    double res =  A.findMedianSortedArrays(nums1, nums2);
    cout << res << endl;
}