#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    //nums1.end() = nums2.begin();
    if (nums1.size() > nums2.size())
    {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        return nums1.size() % 2 == 0 ? (nums1[nums1.size() / 2] + nums1[nums1.size() / 2 - 1]) / 2.0 : nums1[nums1.size() / 2];
    }
    else
    {
        nums2.insert(nums2.end(), nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        return nums2.size() % 2 == 0 ? (nums2[nums2.size() / 2] + nums2[nums2.size() / 2 - 1]) / 2.0 : nums2[nums2.size() / 2];
    }
}
