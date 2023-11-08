//https://leetcode.com/problems/koko-eating-bananas/description/
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        int upper = *std::max_element(piles.begin(), piles.end());
        const int size = piles.size();
        int k, lower=1;

        // if we get back to *upper, upper bound = lower bound
        while(lower+1<upper){
            k = (upper+lower)/2;
            if(!check(piles,h,k)) lower = k;
            else upper = k;
        }
        if(check(piles,h,lower)) return lower;
        return upper;
    }

    bool check(std::vector<int>& piles, int h, int k){
        for(auto it=piles.rbegin(); it!= piles.rend(); it++){
            h-=std::ceil(*it/(double)k);
            if (h<0) return false;
        }
        return true;
    }
};

int main(){
    Solution sol;
    std::vector<int> single({312884470});
    std::cout<<sol.minEatingSpeed(single, 968709470)<<'\n';
    std::vector<int> single2({100000000});
    std::cout<<sol.minEatingSpeed(single2, 2)<<'\n';
    std::vector<int> piles({3,6,7,11});
    std::cout<<sol.minEatingSpeed(piles, 8)<<'\n';
    std::vector<int> piles2({30,11,23,4,20});
    std::cout<<sol.minEatingSpeed(piles2, 5)<<'\n';
    std::cout<<sol.minEatingSpeed(piles2, 6)<<'\n';
}