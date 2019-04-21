#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include<iostream>
// #include<algorithm>

typedef struct ArraySegment {
    size_t left;
    size_t right;

    size_t getMid() {
        return left + (right - left)/2;
    }
} ArraySegment;

class Solution {
    public:
        int search(std::vector<int>& nums, int target);
        int findPivot(std::vector<int>& nums);

    private:
        int getMid(int left, int right);
};

#endif
