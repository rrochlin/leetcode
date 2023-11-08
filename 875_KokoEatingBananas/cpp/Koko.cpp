//https://leetcode.com/problems/koko-eating-bananas/description/
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        int upper = std::vector<int>::max_element(piles.begin(), piles.end());
        const int size = piles.size();
        int k, lower;

        // upper bound for certain pile/h ratios has to be above entry x in array
        auto guess = piles.begin();
        if (h<size*2) guess += size*2-h-1;

        // find an approx upper bound. can use float since piles.length<10^4
        while(!checkK(piles,h,*guess)){
            guess = piles.begin() + std::ceil((guess-piles.begin() + size)/(float)2);
        }

        // if at start of array check with 1, else check with last index
        if (guess != piles.begin()) lower = *(guess-1);
        else lower = 1;
        int upper = *guess;
        
        // if we get back to *upper, upper bound = lower bound
        while(lower<upper){
            k = (upper+lower)/2;
            if(!checkK(piles,h,k)) lower = k;
            else upper = k;
        }

        return k;
    }

    bool checkK(std::vector<int>& piles, int h, int k){
        for(auto it=piles.rbegin(); it!= piles.rend(); it++){
            h-=std::ceil(*it/(double)k);
            if (h<0) {
                return false;
            }
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