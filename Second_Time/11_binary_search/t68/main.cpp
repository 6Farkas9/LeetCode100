#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

vector<int> nums1 = {4};
vector<int> nums2 = {1,2,3,5,6,7};

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int length1 = nums1.size();
        int length2 = nums2.size();
        int k = (length1 + length2 + 1) / 2;
        bool neednext = (length1 + length2) % 2 == 0;
        int i1 = 0, i2 = 0;
        double ans;
        while(true){
            // cout << i1 << "," << i2 << "," << k << endl;
            if(i1 == length1){
                double n1 = nums2[i2 + k - 1];
                double n2 = n1;
                if(neednext)    n2 = nums2[i2 + k];
                ans = (n1 + n2) / 2;
                break;
            }
            if(i2 == length2){
                double n1 = nums1[i1 + k - 1];
                double n2 = n1;
                if(neednext)    n2 = nums1[i1 + k];
                ans = (n1 + n2) / 2;
                break;
            }
            if(k == 1){
                double n1, n2;
                if(nums1[i1] <= nums2[i2])  n1 = nums1[i1++];
                else    n1 = nums2[i2++];
                n2 = n1;
                if(neednext){
                    if(i1 >= length1)   n2 = nums2[i2];
                    else if(i2 >= length2)  n2 = nums1[i1];
                    else n2 = min(nums1[i1], nums2[i2]);
                }
                ans = (n1 + n2) / 2;
                break;
            }
            int j1 = min(i1 + k / 2 - 1, length1 - 1);
            int j2 = min(i2 + k / 2 - 1, length2 - 1);
            if(nums1[j1] <= nums2[j2]){
                k = k - (j1 - i1 + 1);
                i1 = j1 + 1;
            }
            else{
                k = k - (j2 - i2 + 1);
                i2 = j2 + 1;
            }
        }
        return ans;
    }
};

int main(){
    Solution A;
    double res =  A.findMedianSortedArrays(nums1, nums2);
    cout << res << endl;
}