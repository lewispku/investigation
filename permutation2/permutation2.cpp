/*
题目：全排列2
给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

示例 1：
输入：nums = [1,1,2]
输出：
[[1,1,2],[1,2,1],[2,1,1]]

示例 2：
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> temp;
        used_.resize(nums.size(), false);
        std::sort(nums.begin(), nums.end());
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
            if (used_[i] || (i > 0 && nums[i] == nums[i - 1] && !used_[i - 1])) {
                continue;
            }
            used_[i] = true;
            temp.push_back(nums[i]);
            backtrack(nums, temp, start + 1, res);
            temp.pop_back();
            used_[i] = false;
        }
    }

private:
    std::vector<bool> used_;
};

int main() {
    Solution solution;
    std::vector<int> nums = {1, 2, 1};
    std::vector<std::vector<int>> result = solution.permuteUnique(nums);

    for (const auto& permutation : result) {
        for (int num : permutation) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}