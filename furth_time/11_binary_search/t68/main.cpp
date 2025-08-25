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
        double ans;
        int l1 = nums1.size(), l2 = nums2.size();
        int k = (l1 + l2 + 1) / 2;
        bool neednext = !((l1 + l2) % 2);
        int s1 = 0, s2 = 0, e1, e2;
        while(true) {
            if(s1 == l1) {
                if(neednext)
                    ans = static_cast<double>(nums2[s2 + k - 1] + nums2[s2 + k]) / 2;
                else
                    ans = nums2[s2 + k - 1];
                break;
            }
            if(s2 == l2) {
                if(neednext)
                    ans = static_cast<double>(nums1[s1 + k - 1] + nums1[s1 + k]) / 2;
                else
                    ans = nums1[s1 + k - 1];
                break;
            }
            if(k == 1) {
                double m;
                if(nums1[s1] <= nums2[s2])
                    m = nums1[s1++];
                else 
                    m = nums2[s2++];
                double n = m;
                if(neednext) {
                    if(s1 < l1 && s2 < l2)
                        n = min(nums1[s1], nums2[s2]);
                    else if(s1 < l1)
                        n = nums1[s1];
                    else
                        n = nums2[s2];
                }
                ans = (m + n) / 2;
                break;
            }
            e1 = min(l1 - 1, s1 + k / 2 - 1);
            e2 = min(l2 - 1, s2 + k / 2 - 1);
            if(nums1[e1] <= nums2[e2]) {
                k = k - (e1 - s1) - 1;
                s1 = e1 + 1;
            }
            else {
                k = k - (e2 - s2) - 1;
                s2 = e2 + 1;
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