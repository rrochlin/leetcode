#include <vector>
#include <iostream>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size()-1, i = 0;
        const int m = matrix[0].size()-1;
        while (l<=r){
            i = (l+r)/2;
            if (matrix[i][0] <= target && matrix[i][m] >= target) return innerSearch(matrix[i], target);
            else if (matrix[i][m] <= target) l = i + 1;
            else r = i-1;
        }
        return false;
    }

    bool innerSearch(std::vector<int>& matrix, int target){
        int l = 0, r = matrix.size(), i = 0;
        while (l<=r)
        {
            i = (l+r)/2;
            if(matrix[i]==target) return true;
            else if(matrix[i]<target) l = i+1;
            else r = i-1;
        }
        return false;
    }

    bool searchMatrixFast(std::vector<std::vector<int>>& matrix, int target) {
        int row=matrix.size(), col=matrix[0].size();
        int row_index,col_index,start=0,end=row*col-1,mid;
        while(start<=end){
            mid=start+(end-start)/2;
            row_index=mid/col;
            col_index=mid%col;
            if(matrix[row_index][col_index]==target)
            return 1;
            else if(matrix[row_index][col_index]<target)
            start=mid+1;
            else
            end=mid-1;
        }
        return 0;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> small{{1}};
    std::cout<<sol.searchMatrix(small,1)<<std::endl;
    std::cout<<sol.searchMatrix(small,2)<<std::endl;
    std::vector<std::vector<int>> input{{1,3,5,7}, {10,11,16,20}, {23,30,34,60}};
    std::cout<<sol.searchMatrix(input, 11)<<std::endl;
    std::cout<<sol.searchMatrix(input, 9)<<std::endl;
    std::cout<<sol.searchMatrix(input, 34)<<std::endl;
    std::cout<<sol.searchMatrix(input, 61)<<std::endl;
}