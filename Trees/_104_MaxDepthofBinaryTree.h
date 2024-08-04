#ifndef LEETCODE__104_MAXDEPTHOFBINARYTREE_H
#define LEETCODE__104_MAXDEPTHOFBINARYTREE_H
#include "Trees.h"

int helper(TreeNode* root){
    int left=0, right=0;
    if (root->left!=nullptr) left = helper(root->left);
    if (root->right!=nullptr) right = helper(root->right);
    return right>left ? right+1 : left+1;
}

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root == nullptr) return 0;
        return helper(root);
    }
};

#endif //LEETCODE__104_MAXDEPTHOFBINARYTREE_H
