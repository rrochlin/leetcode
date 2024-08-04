

#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& L, std::vector<int>& M) {
        // handle edge cases
        if(L.size() > M.size()) L.swap(M);
        if(L.empty()){
            if (M.size()%2==1) return M[M.size()/2];
            return (M[M.size()/2-1] + M[M.size()/2])/2.0 ;
        }
        int l=0,r=L.size()-1,k,j;
        int total=L.size()+M.size();
        int ll,lr,ml,mr;
        while(true){
            k=std::floor((l+r)/2.0);
            j=total/2-k-2;

            ll=k>=0?L[k]:-INT_MAX;
            lr=k+1<L.size()?L[k+1]:INT_MAX;
            ml=j>=0?M[j]:-INT_MAX;
            mr=j+1<M.size()?M[j+1]:INT_MAX;

            if (ll<=mr && ml<=lr){
                if (total%2==1) return std::min(lr,mr);
                return ((std::max(ll,ml)+std::min(lr,mr))/2.0);
            }
            else if (ll > mr) r=k-1;
            else l=k+1;
        }
        return 0;
    }
};

int main(){
    Solution sol;
    std::vector<int> vec01({-1,0,1,2,3,4,5});
    std::vector<int> vec02({6,7});
    std::cout<<sol.findMedianSortedArrays(vec01, vec02)<<'\n';
    std::vector<int> vec21({1,2,19});
    std::vector<int> vec22({3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18});
    std::cout<<sol.findMedianSortedArrays(vec21, vec22)<<'\n';
    std::vector<int> vec31({1,3});
    std::vector<int> vec32({2,7});
    std::cout<<sol.findMedianSortedArrays(vec31, vec32)<<'\n';
    std::vector<int> vec41({1,2});
    std::vector<int> vec42({-1,3});
    std::cout<<sol.findMedianSortedArrays(vec41, vec42)<<'\n';
    std::vector<int> vec51({1,2});
    std::vector<int> vec52({1,1});
    std::cout<<sol.findMedianSortedArrays(vec51, vec52)<<'\n';
    std::vector<int> vec61({0,0,0,0,0});
    std::vector<int> vec62({-1,0,0,0,0,1});
    std::cout<<sol.findMedianSortedArrays(vec61, vec62)<<'\n';
    std::vector<int> vec71({1,3,4,5});
    std::vector<int> vec72({2});
    std::cout<<sol.findMedianSortedArrays(vec71, vec72)<<'\n';
    std::vector<int> vec81({1,3});
    std::vector<int> vec82({2});
    std::cout<<sol.findMedianSortedArrays(vec81, vec82)<<'\n';
}; 