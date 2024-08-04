#ifndef LEETCODE_100_SAMETREE_H
#define LEETCODE_100_SAMETREE_H
#include "Trees.h"

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr || q==nullptr) return q==p;
        if(p->val!=q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
#endif //LEETCODE_100_SAMETREE_H
