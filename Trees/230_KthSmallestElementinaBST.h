//
// Created by Robert Rochlin on 8/6/24.
// node values are bounded by 0 -> 10^4 so i use negative numbers as codes
//

#ifndef LEETCODE_230_KTHSMALLESTELEMENTINABST_H
#define LEETCODE_230_KTHSMALLESTELEMENTINABST_H
#include "Trees.h"
std::pair<int, bool> helper(TreeNode* root, int k, int res) {
    if(root->left){
        auto temp = helper(root->left, k, res);
        if (temp.second) return {temp.first, true};
        res = temp.first;
    }
    res--;
    // matched value return the value
    if (k+res==0) return {root->val, true};
    if (root->right){
        auto temp = helper(root->right, k, res);
        if (temp.second) return {temp.first, true};
        res = temp.first;
    }
    return {res, false};
}

//better method
std::pair<int,int> find(TreeNode* root, int k) {
    if (root == nullptr) return {-1, 0};
    auto left = find(root->left, k);
    if (left.first != -1) return left;
    k -= left.second;
    if (k == 1) return {root->val, -1};
    k--;
    auto right = find(root->right, k);
    if (right.first != -1) return right;
    return {-1, left.second + right.second + 1};
}

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return find(root, k).second;
    }
};

#endif //LEETCODE_230_KTHSMALLESTELEMENTINABST_H
