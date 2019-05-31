#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *bstToGst(TreeNode *root)
{
    int sum = 0;
    stack<TreeNode *> tree_stack;
    TreeNode *tmp;
    int last_val;
    memset(&last_val, 1, sizeof(int));
    last_val = - (last_val-1);
    tree_stack.push(root);
    while (!tree_stack.empty())
    {
        tmp = tree_stack.top();
        if (tmp->right == NULL && tmp->left == NULL){
            last_val = tmp->val;
            sum += tmp->val;
            tmp->val = sum;
            tree_stack.pop();
            continue;
        }
        if (last_val > tmp->val && !(tmp->right&&(tmp->right->val < last_val))){
            last_val = tmp->val;
            sum += tmp->val;
            tmp->val = sum;
            tree_stack.pop();
            if (tmp->left != NULL){
                tree_stack.push(tmp->left);
                continue;
            }
            continue;
        }
        if (tmp->right != NULL)
        {
            tree_stack.push(tmp->right);
            continue;
        }
    }
    return root;
}

int main()
{
    int a = 0;
    memset(&a, 1, sizeof(a));
    cout << a << endl;
    return 0;
}