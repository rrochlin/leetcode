//https://leetcode.com/problems/koko-eating-bananas/description/
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        std::sort(piles.begin(), piles.end());
        const int size = piles.size();
        int k;
        if (h<size*2) k = piles[size*2-h-1];
        else k=1;
        while(!checkK(piles,h,(double)k)){
            k++;
        }
        return k;
    }

    bool checkK(std::vector<int>& piles, int h, double k){
        for(auto it=piles.rbegin(); it!= piles.rend(); it++){
            h-=*it/k;
            if (h<0) return false;
        }
        return true;
    }
};

int main(){
    Solution sol;
    std::vector<int> single({1000000000});
    std::cout<<sol.minEatingSpeed(single, 2)<<'\n';
    std::vector<int> piles({3,6,7,11});
    std::cout<<sol.minEatingSpeed(piles, 8)<<'\n';
    std::vector<int> piles2({30,11,23,4,20});
    std::cout<<sol.minEatingSpeed(piles2, 5)<<'\n';
    std::cout<<sol.minEatingSpeed(piles2, 6)<<'\n';
}