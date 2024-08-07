//
// Created by Robert Rochlin on 8/6/24.
//

#ifndef LEETCODE_98_VALIDATEBINARYSEARCHTREE_H
#define LEETCODE_98_VALIDATEBINARYSEARCHTREE_H
#include "Trees.h"

// values will always need to be bounded
bool helper(TreeNode* root, int64_t max, int64_t min){
    if (!root) return true;
    if (root->left) {
        if (root->left->val>=root->val) return false;
        if (root->left->val<=min) return false;
    }
    if (root->right) {
        if (root->right->val<=root->val) return false;
        if (root->right->val>=max) return false;
    }
    return helper(root->left, root->val, min) && helper(root->right, max, root->val);
}

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        if (root->left) {
            if (root->left->val>=root->val) return false;
        }
        if (root->right) {
            if (root->right->val<=root->val) return false;
        }
        return helper(root->left, root->val, INT64_MIN) && helper(root->right, INT64_MAX, root->val);
    }
};
#endif //LEETCODE_98_VALIDATEBINARYSEARCHTREE_H
