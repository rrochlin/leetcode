//
// Created by Robert Rochlin on 8/9/24.
//

#ifndef LEETCODE_297_SERIALIZEANDDESERIALIZEBINARYTREE_H
#define LEETCODE_297_SERIALIZEANDDESERIALIZEBINARYTREE_H
#include "Trees.h"
#include <sstream>
#include <stack>
class Codec {
public:

    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        if (!root) return "";
        std::ostringstream res;
        std::deque<TreeNode*> layers{root};
        while(!layers.empty()){
            auto k = layers.size();
            for(int i=0; i<k; i++){
                if(layers.front()) {
                    res << layers.front()->val;
                    layers.push_back(layers.front()->left);
                    layers.push_back(layers.front()->right);
                }
                res<<",";
                layers.pop_front();
            }
        }
        return res.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        if(data == "") return {};
        std::stringstream ss(data);
        std::string value;
        std::getline(ss, value, ',');
        auto head = new TreeNode(std::stoi(value));
        auto temp = head;
        std::deque<TreeNode*> stack{head};
        bool left=true;
        while(std::getline(ss, value, ',')){
            TreeNode *next;
            if (!value.empty()) {
                next = new TreeNode(std::stoi(value));
                stack.push_back(next);
                if (left) temp->left = next;
                else {
                    temp->right = next;
                }
            }
            if(!left) {
                stack.pop_front();
                temp = stack.front();
            }
            left=!left;
        }
        return head;
    }
};

#endif //LEETCODE_297_SERIALIZEANDDESERIALIZEBINARYTREE_H
