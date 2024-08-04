#ifndef LEETCODE__100_SAMETREE_H
#define LEETCODE__100_SAMETREE_H
#include "Trees.h"

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p==nullptr || q==nullptr) return q==p;
    if(p->val!=q->val) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr || subRoot==nullptr) return root==subRoot;
        if(root->val==subRoot->val && isSameTree(root, subRoot)) return true;
        return isSubtree(root->right, subRoot) || isSubtree(root->left, subRoot);
    }
};
#endif //LEETCODE__100_SAMETREE_H
