#include "Trees.h"
#include "297_SerializeandDeserializeBinaryTree.h"

int main() {
//    auto sol = new Solution();
    auto codec = new Codec();
    auto tree = makeTree(std::vector<int>{4,-7,-3,INT_MIN,INT_MIN,-9,-3,9,-7,-4,INT_MIN,6,INT_MIN,-6,-6,INT_MIN,INT_MIN,0,6,5,INT_MIN,9,INT_MIN,INT_MIN,-1,-4,INT_MIN,INT_MIN,INT_MIN,-2});
    printBT(tree);
//    auto vec1 = std::vector<int>{1,2,3};
    std::cout<<codec->serialize(tree)<<"\n";
    printBT(codec->deserialize(codec->serialize(tree)));
}