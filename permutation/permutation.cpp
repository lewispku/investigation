/*
题目：全排列
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

示例 1：
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

示例 2：
输入：nums = [0,1]
输出：[[0,1],[1,0]]

示例 3：
输入：nums = [1]
输出：[[1]]
*/

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> temp;
        used_.resize(nums.size(), false);
        backtrack(nums, temp, 0, res);
        return res;
    }

private:
    void backtrack(std::vector<int>& nums, std::vector<int>& temp, int start, std::vector<std::vector<int>>& res) {
        if (start == nums.size()) {
            res.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (!used_[i]) {
                used_[i] = true;
                temp.push_back(nums[i]);
                backtrack(nums, temp, start + 1, res);
                temp.pop_back();
                used_[i] = false;
            }
        }
    }

private:
    std::vector<bool> used_;
};

int main() {
    Solution solution;
    std::vector<int> nums = {1, 2, 3};
    std::vector<std::vector<int>> result = solution.permute(nums);

    for (const auto& permutation : result) {
        for (int num : permutation) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}