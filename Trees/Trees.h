#ifndef LEETCODE_TREES_H
#define LEETCODE_TREES_H
#include <vector>
#include <deque>
#include <iostream>
#include "../HelperFuncts/PrintBT.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* makeTree(std::vector<int> array){
    auto head = new TreeNode(array[0]);
    TreeNode* temp = head;
    std::deque<TreeNode*> stack;
    for (int i=1; i<array.size();i++){
        if (array[i] == -1) continue;
        TreeNode* next = new TreeNode(array[i]);
        stack.push_back(next);
        if(i%2) temp->left = next;
        else {
            temp->right = next;
            temp = stack.front();
            stack.pop_front();
        }
    }
    return head;
}

#endif //LEETCODE_TREES_H
