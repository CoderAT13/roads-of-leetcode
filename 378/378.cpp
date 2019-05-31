#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int kthSmallest(vector<vector<int> > &matrix, int k)
{
    int n = matrix.size();
    int left = matrix[0][0], right = matrix[n - 1][n - 1];
    int mid = 0;
    while (left < right)
    {
        /* 计算中位数 */
        mid = left + (right - left) / 2;
        int num = 0;

        /* 每行里找到这个中位数的上界
         * 计算比这个中位数小的元素的个数
        */
        for (int i = 0; i < n; i++)
        {
            int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            num += pos;
        }
        /* 如果个数比k少，那么k th在中位数后半边，否则中位数左半边，知道left == right*/
        if (num < k)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return left;
}