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
                if (i > s && candidates[i] == candidates[i - 1])
                    continue;
                v.push_back(candidates[i]);
                // i+1 because you can take it only once.
                solve(candidates, target - candidates[i], v, i + 1);
                // backtrack as you have found the answer from this combination now remove the element and add another in order to find other combination.
                v.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        solve(candidates, target, v, 0);
        return ans;
    }
};
// Same as combination 1 but twist is that you cannot take same element more than once, an element can only be used once.
// Now duplicates are not allowed,
// eg- 1 1 2 5  target=8
// [1,2,5] one is this and another will be [1,2,5] as there are 2 ones, so both are same. To get uniques/distinct, what we do is that if the next element is same as that of the previous one, we move forward.
// when we move to 1 at 1st index, it is same as previous i.e a at 0index, so ignore it, move forward.

// Elements are given in array and you have to find a combinations of those element and sum of that combination should be equal to target.
// Now i want sum so i have to iterate over the array and another reason is that when you have to take one element and there are multiple possibilities then a loop will always come in recursive case.
// i can take 2 , 3, 6, 7... so multiple possibilities
// Since we want to have vector so we are taking a vetctor v to store one combination and all combinations will be stored in ans 2d vector.