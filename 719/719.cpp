#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int smallestDistancePair(vector<int> &nums, int k)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int left = nums[1] - nums[0], right = nums[n - 1] - nums[0];
    for (int i = 0; i < n - 1; ++i)
    {
        if (left > nums[i + 1] - nums[i])
            left = nums[i + 1] - nums[i];
    }

    while (left < right)
    {
        int num = 0;
        int mid = (right + left) / 2;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int j = i;
            while (j < n && nums[j] - nums[i] <= mid) j++;
            num += j - i - 1;
        }
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

int main()
{
    int n, k;
    vector<int> a;
    a.push_back(1);
    a.push_back(3);
    a.push_back(1);
    cout << smallestDistancePair(a, 1) << endl;
    return 0;
}