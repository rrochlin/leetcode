#ifndef LEETCODE_104_MAXDEPTHOFBINARYTREE_H
#define LEETCODE_104_MAXDEPTHOFBINARYTREE_H
#include "Trees.h"

// Since this is a BST once we have found a node in the range (p, q) we have our answer.
// large > small
TreeNode* helper(TreeNode* root, int large, int small) {
    if (large < root->val) return helper(root->left, large, small);
    if (small > root->val) return helper(root->right, large, small);
    return root;
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val) return helper(root, p->val, q->val);
        return helper(root, q->val, p->val);
    }
};

#endif //LEETCODE_104_MAXDEPTHOFBINARYTREE_H
