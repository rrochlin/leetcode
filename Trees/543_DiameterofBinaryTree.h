#ifndef LEETCODE_543_DIAMETEROFBINARYTREE_H
#define LEETCODE_543_DIAMETEROFBINARYTREE_H
#include "Trees.h"


std::pair<int,int> helper(TreeNode* root){
    int left=0, right=0, rc=0, lc=0;
    std::pair<int,int> l, r;
    if (root->left!=nullptr) l = helper(root->left);
    if (root->right!=nullptr) r = helper(root->right);
    left = l.first;
    lc = l.second;
    right = r.first;
    rc = r.second;
    int best = rc>lc ? rc : lc;
    best = best>right+left ? best : right+left;
    return {right>left ? right+1 : left+1, best};
}

class Solution {
public:
    int diameterOfBinaryTree(TreeNode *root) {
        if (root == nullptr) return 0;
        return helper(root).second;
    }
};

#endif //LEETCODE_543_DIAMETEROFBINARYTREE_H
