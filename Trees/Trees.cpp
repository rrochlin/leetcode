#include "Trees.h"
#include "_543_DiameterofBinaryTree.h"

int main() {
    auto sol = new Solution();
//    int nums[] = {4,2,7,1,3,6,9};
    int nums[] = {1,2,3,4,5};
    int n = sizeof(nums) / sizeof(nums[0]);
    auto vec = std::vector<int> (nums, nums+n);
    auto tree = makeTree(vec);
    printBT(tree);
    std::cout<<"\n"<< sol->diameterOfBinaryTree(tree);


}