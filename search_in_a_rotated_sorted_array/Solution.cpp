#include "Solution.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>

#define DEBUG 1

using namespace std;

// [4,5,6,7,8,9,0,1,2]

int Solution::getMid(int left, int right) {
    return left + (right-left)/2;
}

int Solution::findPivot(vector<int>& nums) {
    ArraySegment arrSeg {0, nums.size()-1};
    // int findPivotCount = 0;
    while (true) {
        // cout << "findPivotCount : " << findPivotCount++ << endl; 
        int left = arrSeg.left;
        int right = arrSeg.right;
        int mid = arrSeg.getMid();

        if (nums[mid] > nums[mid+1]) {
            return mid;
        } else if (nums[mid-1] > nums[mid]) { 
            return mid - 1;
        }

        if ((right - left) < 2) {
            return right;
        }

        else if (nums[left] > nums[mid]) { 
            right = mid - 2;
        } else {
            left = mid + 1;
        }

        arrSeg.left = left;
        arrSeg.right = right;
    }
}

int Solution::search(vector<int>& nums, int target) {

    if (nums.empty()) return -1;
    int pivot = findPivot(nums);
    //cout << "pivot : " << pivot << " target : " << target << endl; 
    //for (auto num : nums) {
    //    cout << num << " ";
    //}
    //cout << endl;

    if (nums[pivot] < target) return -1;
    if (nums[pivot] == target) return pivot;

    ArraySegment arrSeg {0, nums.size()-1};

    if (nums[arrSeg.left] == target) return arrSeg.left;
    if (nums[arrSeg.right] == target) return arrSeg.right;
    if (nums[arrSeg.getMid()] == target) return arrSeg.getMid();

    if ((arrSeg.right - arrSeg.left) < 3) {
        return -1;
    }

    if (nums[arrSeg.left] < target) {
        arrSeg.right = pivot - 1; 
    } else {
        arrSeg.left = pivot + 1;
    }

    while (true) {
        int left = arrSeg.left;
        int right = arrSeg.right;
        int mid = arrSeg.getMid();

        if (nums[left] == target) return left;
        if (nums[right] == target) return right;
        if (nums[mid] == target) return mid;

        if ((right - left) < 3) {
            return -1;
        }

        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }

        arrSeg.left = left;
        arrSeg.right = right;
    }
}
