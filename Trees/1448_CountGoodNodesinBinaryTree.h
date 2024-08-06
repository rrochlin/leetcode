//
// Created by Robert Rochlin on 8/5/24.
//

#ifndef LEETCODE_1448_COUNTGOODNODESINBINARYTREE_H
#define LEETCODE_1448_COUNTGOODNODESINBINARYTREE_H
#include "Trees.h"
int helper(TreeNode* root, int max){
    if (!root) return 0;
    if (root->val>max) max = root->val;
    return helper(root->left, max) + helper(root->right, max) + (root->val >= max);
}

class Solution {
public:
    int goodNodes(TreeNode* root) {
        return helper(root, INT_MIN);
    }
};
#endif //LEETCODE_1448_COUNTGOODNODESINBINARYTREE_H
