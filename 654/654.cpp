#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *constructMaximumBinaryTree(vector<int> &nums)
{
    vector<TreeNode*> stk;
    for (int i = 0; i < nums.size(); ++i){
        TreeNode* node = new TreeNode(nums[i]);
        
        /**
         * stk is all the element in nums[i]'s left
         * in the while, we can confirm that the bottom of stk is the largest one beyonf (i-1)
         * if nums[i] > the max of stk
         * all of the elements pop
         */

        while(!stk.empty() && stk.back()->val < nums[i]){
            node->left = stk.back();
            stk.pop_back();
        }

        /**
         * node must be the max beyond the stk.top right
         */ 

        if (!stk.empty()){
            stk.back()->right = node;
        }
        stk.push_back(node);
    }
    return stk.front();
}



