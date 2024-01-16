#include <string>
#include <iostream>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.size()<t.size()) return "";
        int l=0, r=0;
        int minl=0, minr=100'001;
        int count[128]={0}, unique=0;
        for (int i=0; i<t.size(); i++) if(count[t[i]]++==0) unique++;
        while (r<s.size()){
            if (count[s[r++]]--==1) unique--;
            if (unique==0) {
                while (true)
                    if (count[s[l++]]++==0) {unique++; break;}
                if (r-l<minr-minl) minr=r, minl=l-1;
            }
        }
        if (minr>100'000) return "";
        return s.substr(minl, minr-minl);
    }
};


int main(){
    Solution sol;
    std::string s = "ADOBECODEBANC", t = "ABC";
    std::cout<<sol.minWindow(s,t)<<'\n';
    s = "a", t = "a";
    std::cout<<sol.minWindow(s,t)<<'\n';
    s = "a", t = "aa";
    std::cout<<sol.minWindow(s,t)<<'\n';
    s = "cabwefgewcwaefgcf", t = "cae";
    std::cout<<sol.minWindow(s,t)<<'\n';
}; 