#include <iostream>
#include <vector>
#include <stack>
class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        std::stack<std::pair<int,int> > elements;
        int largest = 0;
        int tallest = 0;
        int i=0;
        for (auto it = heights.begin(); it!=heights.end(); it++,i++){
            int effI = i;
            if (*it<tallest){
                while (!elements.empty() && elements.top().first > *it) {
                    std::pair<int,int> elem = elements.top();
                    elements.pop();
                    int next = elem.first*(i-elem.second);
                    if (largest < next) largest = next;
                    effI = elem.second;
                }
            }
            elements.push(std::pair<int,int>(*it, effI));
            tallest = *it;
        }
        while (!elements.empty()) {
            std::pair<int,int> elem = elements.top();
            elements.pop();
            int next = elem.first*(i-elem.second);
            if (largest < next) largest = next;
        }
        return largest;
    }
};

int main() {
    Solution sol;
    int myints[] = {2,1,5,6,2,3};
    std::vector<int> input(myints, myints + sizeof(myints) / sizeof(int) );
    std::cout<<sol.largestRectangleArea(input)<<std::endl;
    int myints2[] = {2,4};
    std::vector<int> input2(myints2, myints2 + sizeof(myints2) / sizeof(int) );
    std::cout<<sol.largestRectangleArea(input2)<<std::endl;
    int myints3[] = {2,1,2};
    std::vector<int> input3(myints3, myints3 + sizeof(myints3) / sizeof(int) );
    std::cout<<sol.largestRectangleArea(input3)<<std::endl;
}