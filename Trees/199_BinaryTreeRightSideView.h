//
// Created by Robert Rochlin on 8/4/24.
//

#ifndef LEETCODE_199_BINARYTREERIGHTSIDEVIEW_H
#define LEETCODE_199_BINARYTREERIGHTSIDEVIEW_H
#include "Trees.h"

class Solution {
public:
    std::vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        std::vector<int> out;
        std::deque<TreeNode *> nodeQ{root};
        while (!nodeQ.empty()) {
            int k = nodeQ.size();
            for (int i = 0; i < k-1; i++) {
                if (nodeQ.front()->left) nodeQ.push_back(nodeQ.front()->left);
                if (nodeQ.front()->right) nodeQ.push_back(nodeQ.front()->right);
                nodeQ.pop_front();
            }
            if (nodeQ.front()->left) nodeQ.push_back(nodeQ.front()->left);
            if (nodeQ.front()->right) nodeQ.push_back(nodeQ.front()->right);
            out.push_back(nodeQ.front()->val);
            nodeQ.pop_front();
        }
        return out;
    }
};
#endif //LEETCODE_199_BINARYTREERIGHTSIDEVIEW_H
