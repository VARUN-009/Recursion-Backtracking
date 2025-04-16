class Solution
{
public:
    vector<vector<int>> ans;
    void solve(vector<int> &nums, int index)
    {
        // base case
        if (index >= nums.size())
        {
            ans.push_back(nums);
            return;
        }

        // recursive case
        for (int j = index; j < nums.size(); j++)
        {
            swap(nums[index], nums[j]);
            solve(nums, index + 1);
            swap(nums[index], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        solve(nums, 0);
        return ans;
    }
};