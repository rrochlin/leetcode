//
// Created by Robert Rochlin on 8/8/24.
//

#ifndef LEETCODE_124_BINARYTREEMAXIMUMPATHSUM_H
#define LEETCODE_124_BINARYTREEMAXIMUMPATHSUM_H
#include "Trees.h"

std::pair<int, int> helper(TreeNode* root){
    std::pair<int, int> l{-1001,-1001}, r{-1001,-1001};
    if(root->left) l = helper(root->left);
    else if(root->right == nullptr) return {root->val, root->val};
    if(root->right) r = helper(root->right);
    int maxPath = l.second>r.second ? l.second+root->val : r.second+root->val;
    if (root->val>maxPath) maxPath=root->val;
    int prevMax = l.first>r.first ? l.first : r.first;
    int max = maxPath > (l.second + root->val + r.second) ? maxPath : (l.second + root->val + r.second);
    return {max>prevMax ? max : prevMax, maxPath};
}

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        return helper(root).first;
    }
};

#endif //LEETCODE_124_BINARYTREEMAXIMUMPATHSUM_H
