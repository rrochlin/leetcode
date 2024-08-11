//
// Created by Robert Rochlin on 8/10/24.
//

#ifndef LEETCODE_144_BTPREORDERTRAVERSAL_H
#define LEETCODE_144_BTPREORDERTRAVERSAL_H
#include "Trees.h"
class Solution {
public:

    std::vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        std::vector<int> res{root->val};
        auto l = preorderTraversal(root->left);
        auto r = preorderTraversal(root->right);
        res.reserve(l.size()+r.size()+1);
        res.insert(res.end(), l.begin(), l.end());
        res.insert(res.end(), r.begin(), r.end());
        return res;
    }
};

#endif //LEETCODE_144_BTPREORDERTRAVERSAL_H
