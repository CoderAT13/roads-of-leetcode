#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int> > result;
        if (nums1.empty() || nums2.empty() || k <= 0)
            return result;
        auto comp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];};

        priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(comp)> min_heap(comp);
        min_heap.emplace(0, 0);
        while(k-- > 0 && min_heap.size())
        {
            auto idx_pair = min_heap.top(); 
            min_heap.pop();
            vector<int> tmp;
            tmp.push_back(nums1[idx_pair.first]);
            tmp.push_back(nums2[idx_pair.second]);
            result.push_back(tmp);

            /* 如果1不越界 */
            if (idx_pair.first + 1 < nums1.size())
                min_heap.emplace(idx_pair.first + 1, idx_pair.second);
            /* 如果1是第一个且，2不越界 */
            if (idx_pair.first == 0 && idx_pair.second + 1 < nums2.size())
                min_heap.emplace(idx_pair.first, idx_pair.second + 1);
        }
        return result;
}