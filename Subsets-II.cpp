class Solution
{
public:
    set<vector<int>> s;
    void solve(vector<int> &nums, vector<int> output, int index)
    {
        // base case
        if (index >= nums.size())
        {
            s.insert(output);
            return;
        }

        // recursive case
        // ith character not included
        solve(nums, output, index + 1);
        // ith character included
        output.push_back(nums[index]);
        solve(nums, output, index + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<int> output;
        sort(nums.begin(), nums.end());
        solve(nums, output, 0);
        vector<vector<int>> ans(s.begin(), s.end());
        // for(auto i:s) ans.push_back(i);
        return ans;
    }
};