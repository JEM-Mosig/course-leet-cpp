// LeetCode problem "Container with Most Water"
// https://leetcode.com/problems/container-with-most-water/

#include <iostream>
#include <vector>

// A type-safe minimum macro (https://stackoverflow.com/a/3437484/6760298)
#define min(a, b) ({ \
  __typeof__ (a) _a = (a); \
  __typeof__ (b) _b = (b); \
  _a < _b ? _a : _b; \
})

class Solution {
public:

    // Naive solution where we try all combinations
    static int maxArea_naive(std::vector<int>& height) {

        if (height.empty())
            return 0;

        int max_area = 0, area = 0;

        for (int i = 0; i < height.size(); i++) {
            for (int j = 0; j < height.size(); j++){
                if (i != j) {
                    area = abs(i - j) * min(height[i], height[j]);
                    if (area > max_area) {
                        max_area = area;
                    }
                }
            }
        }

        return max_area;
    }

    // Faster solution where we close in from both sides
    static int maxArea(std::vector<int>& height) {

        if (height.empty())
            return 0;

        unsigned int left = 0;
        unsigned int right = height.size() - 1;
        int max_area = 0, area;

        while(left != right) {
            area = (right - left) * min(height[left], height[right]);
            if (area > max_area)
                max_area = area;

            // Move the index that points to the smaller column towards the other one
            if (height[left] > height[right]) {
                right--;
            } else {
                left++;
            }
        }

        return max_area;
    }
};

int main() {
    std::vector<int> input = {1,8,6,2,5,4,8,3,7};
    std::cout << Solution::maxArea_naive(input) << " | " << Solution::maxArea(input) << std::endl;

    input = {10, 1, 2, 1, 2, 1, 10};
    std::cout << Solution::maxArea_naive(input) << " | " << Solution::maxArea(input) << std::endl;

    input = {1, 1};
    std::cout << Solution::maxArea_naive(input) << " | " << Solution::maxArea(input) << std::endl;

    input = {1, 2, 1, 2, 1000, 1, 2, 1};
    std::cout << Solution::maxArea_naive(input) << " | " << Solution::maxArea(input) << std::endl;

    input = {1, 2, 1, 2, 1000, 800, 2, 1};
    std::cout << Solution::maxArea_naive(input) << " | " << Solution::maxArea(input) << std::endl;

    input = {7};
    std::cout << Solution::maxArea_naive(input) << " | " << Solution::maxArea(input) << std::endl;

    input = {};
    std::cout << Solution::maxArea_naive(input) << " | " << Solution::maxArea(input) << std::endl;

    return 0;
}