class Solution
{
public:
    vector<vector<int>> ans;
    void solve(vector<int> &candidates, int target, vector<int> &v, int s)
    {
        // base Case
        if (target == 0)
        {
            ans.push_back(v);
            return;
        }
        // recursive Case
        for (int i = s; i < candidates.size(); i++)
        {
            // If i want to take one element then it should be smaller or equal to sum, if yes take it and subtract it's value from target.
            if (target >= candidates[i])
            {
                v.push_back(candidates[i]);
                // Now i can take that element multiple times, so do not move forward, keep your position at this element only, that's why i not i+1.
                solve(candidates, target - candidates[i], v, i);
                // backtrack as you have found the answer from this combination now remove the element and add another in order to find other combination.
                v.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> v;
        solve(candidates, target, v, 0);
        return ans;
    }
};
// Elements are given in array and you have to find a combinations of those element and sum of that combination should be equal to target.
// Now i want sum so i have to iterate over the array and another reason is that when you have to take one element and there are multiple possibilities then a loop will always come in recursive case.
// i can take 2 , 3, 6, 7... so multiple possibilities
// Since we want to have vector so we are taking a vetctor v to store one combination and all combinations will be stored in ans 2d vector.