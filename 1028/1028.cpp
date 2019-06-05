#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* recoverFromPreorder(string S) {
    vector<TreeNode*> stk;
    for (int p = 0, len = 0, level = 0; p < S.length(); p+=len){
        len = 0;
        level = 0;
        while(S[p]=='-') ++level, ++p;
        while(p + len < S.length() && S[p+len] != '-') ++len;
        TreeNode* T = new TreeNode(stoi(S.substr(p, len)));
        while (stk.size() > level) stk.pop_back();
        if (!stk.empty()) {
            if (stk.back()->left == NULL) stk.back()->left = T;
            else stk.back()->right = T;
        }
        stk.push_back(T);
    }
    return stk[0];
}

