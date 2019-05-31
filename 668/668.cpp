#include <iostream>
#include <vector>
using namespace std;

int findKthNumber(int m, int n, int k) {
    unsigned int left = 1, right = m * n;
    while(left < right){
        unsigned int mid = (left + right)/2;
        int num = 0;
        for (int i = 1; i <= m; i++){
            num += (mid/i < n ? mid/i : n);
        }
        if (num < k) left = mid+1;
        else right = mid;
        
    }
    return left;
}

int main(){
    cout << findKthNumber(1,3,2) << endl;
    return 0;
}