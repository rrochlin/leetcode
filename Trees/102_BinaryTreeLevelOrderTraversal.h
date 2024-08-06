//
// Created by Robert Rochlin on 8/4/24.
// returns the values of the binary tree level by level
// left to right
//

#ifndef LEETCODE_102_BINARYTREELEVELORDERTRAVERSAL_H
#define LEETCODE_102_BINARYTREELEVELORDERTRAVERSAL_H
#include "Trees.h"
class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        std::vector<std::vector<int>> out;
        std::deque<TreeNode*> nodeQ{root};
        while(!nodeQ.empty()){
            int k = nodeQ.size();
            std::vector<int> current;
            for(int i = 0; i<k; i++){
                if(nodeQ.front()->left) nodeQ.push_back(nodeQ.front()->left);
                if(nodeQ.front()->right) nodeQ.push_back(nodeQ.front()->right);
                current.push_back(nodeQ.front()->val);
                nodeQ.pop_front();
            }
            out.push_back(current);
        }
        return out;
    }
};


#endif //LEETCODE_102_BINARYTREELEVELORDERTRAVERSAL_H
