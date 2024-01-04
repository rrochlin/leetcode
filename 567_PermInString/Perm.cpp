#include <iostream>
#include <string>

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        if (s1.length()>s2.length()) return false;
        int count[26]={0}, unique=0;
        int l=0,r=s1.length()-1;
        for (char c : s1) if(count[c-'a']++==0) unique++;
        for (int i=0; i<s1.length()-1; i++){
            if(count[s2[i]-'a']--==0) unique++;
            else if(count[s2[i]-'a']==0) unique--;
        }
        while (r<s2.length()){
            if(count[s2[r]-'a']--==0) unique++;
            else if(count[s2[r]-'a']==0) unique--;
            if(unique==0) return true;
            if(count[s2[l]-'a']++==0) unique++;
            else if(count[s2[l]-'a']==0) unique--;
            r++; l++;
        }
        return false;
    }
};

int main(){
  Solution sol;
  std::string s = "hello";
  std::string s2 = "ooolleoooleh";
  std::cout<<sol.checkInclusion(s, s2)<<"\n";
}; 