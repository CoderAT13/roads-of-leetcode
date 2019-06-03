#include <stack>
#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int kthSmallest(TreeNode *root, int k)
{
    int res = -1, count = 0;
    TreeNode* current = root;
    stack<TreeNode*> tree;
    tree.push(root);
    while (count != k)
    {
        root = tree.top();
        if (current != root->right){
            if (current != root->left){
                if (root->left != NULL){
                    tree.push(root->left);
                    continue;
                }
            }
            count++;
            res = root->val;
            if (root->right != NULL){
                tree.push(root->right);
                continue;
            }
        }
        current = root;
        tree.pop();
    }
    return res;
}

int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);
    cout << kthSmallest(root, 3) << endl;
    return 0;
}