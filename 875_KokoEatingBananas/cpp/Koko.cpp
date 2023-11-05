//https://leetcode.com/problems/koko-eating-bananas/description/
#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        std::sort(piles.begin(), piles.end());
        const int size = piles.size();
        if (h<size*2) return piles[size*2-h-1];
        else return 0;
    }
};

int main(){
    Solution sol;
    std::vector<int> piles({3,6,7,11});
    std::cout<<sol.minEatingSpeed(piles, 8)<<'\n';
    std::vector<int> piles2({30,11,23,4,20});
    std::cout<<sol.minEatingSpeed(piles2, 5)<<'\n';
    std::cout<<sol.minEatingSpeed(piles2, 6)<<'\n';
}