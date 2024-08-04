#ifndef LEETCODE__110_BALANCEDBINARYTREE_H
#define LEETCODE__110_BALANCEDBINARYTREE_H
#include "Trees.h"
#include <cmath>

class unbalanced : public std::exception {};

std::pair<int, bool> helper(TreeNode* root){
    std::pair<int, bool> l{0, true}, r{0, true};
    if (root->left!=nullptr) {
        l = helper(root->left);
        if (!l.second) throw unbalanced();
    }
    if (root->right!=nullptr) {
        r = helper(root->right);
        if (!r.second) throw unbalanced();
    }
    int left = l.first, right = r.first;
    bool lc = l.second, rc = r.second;
    if (std::abs(left-right)>1) return {0, false};
    return {right>left ? right+1 : left+1, true};
}

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root==nullptr) return true;
        try{
            return helper(root).first;
        }
        catch (unbalanced e) {
            return false;
        }
    }
};
#endif //LEETCODE__110_BALANCEDBINARYTREE_H
