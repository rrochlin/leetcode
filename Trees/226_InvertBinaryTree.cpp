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

class Solution {
public:

    TreeNode* invertTree(TreeNode* root) {
        if (root==nullptr) return nullptr;
        if (root->right != nullptr) invertTree(root->right);
        if (root->left!= nullptr) invertTree(root->left);
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = temp;
        return root;
    }
};


int main() {
    auto sol = new Solution();
//    int nums[] = {4,2,7,1,3,6,9};
    int nums[] = {2,-1,3,-1,1};
    int n = sizeof(nums) / sizeof(nums[0]);
    auto vec = std::vector<int> (nums, nums+n);
    auto tree = makeTree(vec);
    auto res = sol->invertTree(tree);
    printBT(tree);
    printBT(res);


}