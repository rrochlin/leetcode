#include "Trees.h"
#include "_110_BalancedBinaryTree.h"

int main() {
    auto sol = new Solution();
//    int nums[] = {4,2,7,1,3,6,9};
    int nums[] = {1,2,2,3,3,-1,-1,4,4};
    int n = sizeof(nums) / sizeof(nums[0]);
    auto vec = std::vector<int> (nums, nums+n);
    auto tree = makeTree(vec);
    printBT(tree);
    if(sol->isBalanced(tree)) std::cout<<"true";
    else std::cout<<"false";


}