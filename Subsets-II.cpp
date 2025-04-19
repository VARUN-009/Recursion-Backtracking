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
        // ith character excluded
        solve(nums, output, index + 1);
        // ith character included
        output.push_back(nums[index]);
        solve(nums, output, index + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<int> output;
        // need to sort jiss se ki saare elements ek saath aajaye jo same ho as answer sorted way m chahiye
        sort(nums.begin(), nums.end());
        solve(nums, output, 0);
        vector<vector<int>> ans(s.begin(), s.end());
        // for(auto i:s) ans.push_back(i);
        return ans;
    }
};
/*
Duplicate ni hone chahiye means take a set. Jab bhi unique, no duplicate aaye toh chances hai ki set use hoga.

Time Complexity (TC): O(2^n * n)
You're generating all 2^n possible subsets (even duplicates initially).

For each subset, you're inserting a vector of size ≤ n into the set.
Set insertion of a vector takes O(n log m) where m is the number of elements in the set so far (because set uses red-black tree), but we generally simplify to O(n) for insertion.

So total time:
2^n subsets * O(n) time to insert each vector into set = O(2^n * n)
Note: Sorting input takes O(n log n), but that's negligible compared to O(2^n * n).

Space Complexity (SC): O(2^n * n)
Set can hold up to 2^n subsets, each of size up to n ⇒ O(2^n * n)

Recursion stack will use space up to O(n) (maximum depth of the tree)

So total space is dominated by the set of subsets: O(2^n * n)
*/

// SOLUTION - 2
class Solution
{
public:
    vector<vector<int>> ans;
    void solve(vector<int> &nums, vector<int> output, int index)
    {
        // base case
        // har recursion level call m dalna padega sabse pehle toh empty hi aajayega
        ans.push_back(output);

        // recursive case
        // sort toh kar hi rakha hai and agr mera current element pehle wale ke equal hai toh same hi answer aajayega na duplicate ho jyega so don't take it
        for (int start = index; start < nums.size(); start++)
        {
            // duplicate hua toh ni lena bss liya then aage and then jo liya tha vo hta diya
            if (start == index || nums[start] != nums[start - 1])
            {
                output.push_back(nums[start]);
                solve(nums, output, start + 1);
                output.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<int> output;
        // need to sort jiss se ki saare elements ek saath aajaye jo same ho as answer sorted way m chahiye
        sort(nums.begin(), nums.end());
        solve(nums, output, 0);
        return ans;
    }
};
/*
TC - O(2^n) + O(nlogn) 
SC - O(n) recursion stack space + ans m O(2^n) subsets

*/