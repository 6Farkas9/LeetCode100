#include <iostream>
#include <vector>
#include <climits>
#include <math.h>

using namespace std;
int n = 13;

class Solution {
public:
    int numSquares(int n) {
        vector<int> data;
        data.resize(n,1);
        for(int i = 0, i_n = 1; i < n; i++, i_n++){
            double sqrt_double = sqrt(i_n);
            int sqrt_int = int(sqrt_double);
            if(sqrt_int != sqrt_double){
                int temp = INT_MAX;
                for(int j = 1; j <= sqrt_int; j++){
                    int pow_int = pow(j,2);
                    if(data[i - pow_int] + 1 < temp)    temp = data[i - pow_int] + 1;
                }
                data[i] = temp; 
            }
        }
        return data[n-1];
    }
};

int main(){
    Solution A;
    auto ans = A.numSquares(n);

    cout << ans << endl;

    // for(auto val : ans){
    //     for(auto vval : val){
    //         cout << vval << " ";
    //     }
    //     cout << endl;
    // }
}