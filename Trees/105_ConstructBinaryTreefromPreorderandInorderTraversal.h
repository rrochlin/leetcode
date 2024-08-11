//
// Created by Robert Rochlin on 8/6/24.
//

#ifndef LEETCODE_105_CONSTRUCTBINARYTREEFROMPREORDERANDINORDERTRAVERSAL_H
#define LEETCODE_105_CONSTRUCTBINARYTREEFROMPREORDERANDINORDERTRAVERSAL_H
#include "Trees.h"
#include <unordered_map>
// this seemed to work in one instance but using on another problem is giving lots of errors
class BestSolution {
public:
    TreeNode* helper(std::vector<int>& preorder, int prestart, int preend, std::vector<int>& inorder, int instart, int inend, std::unordered_map<int,int>& mp){
        if(prestart>preend || instart>inend)
            return NULL;
        TreeNode* root= new TreeNode(preorder[prestart]);
        int x= mp[preorder[prestart]];
        int numleft= x-instart;
        root->left= helper(preorder, prestart+1, prestart+numleft, inorder, instart, x-1, mp);
        root->right= helper(preorder, prestart+numleft+1, preend, inorder, x+1, inend, mp);
        return root;


    }
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        std::unordered_map<int,int> mp;
        //value, index
        for(int i=0; i<preorder.size(); i++){
            mp[inorder[i]]=i;
        }
        return helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mp);
    }
};
class Solution {
public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        if(m_preorder.empty()) m_preorder = preorder;
        auto root = new TreeNode(m_preorder[0]);
        if (inorder.empty()) return root;
        auto root_it_i = std::find(inorder.begin(), inorder.end(), preorder[0]);
        m_preorder.erase(m_preorder.begin());
        if (root_it_i!=inorder.begin()&&root_it_i!=inorder.end()){
            // issue here is we don't know how many nodes will be consumed
            auto i_temp = std::vector<int>(inorder.begin(),root_it_i);
            root->left = buildTree(m_preorder, i_temp);
        }
        if (root_it_i!=inorder.end()-1&&root_it_i!=inorder.end()){
            auto i_temp = std::vector<int>(root_it_i+1,inorder.end());
            root->right = buildTree(m_preorder, i_temp);
        }
        return root;
    }
private:
    std::vector<int> m_preorder = std::vector<int>();
};
#endif //LEETCODE_105_CONSTRUCTBINARYTREEFROMPREORDERANDINORDERTRAVERSAL_H
