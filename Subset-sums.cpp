class Solution
{
private:
    vector<int> ans;
    void helper(int idx, vector<int> &arr, int sum)
    {
        // base case
        // agr saare elements khatam ho gaye toh abhi tak ka jo bhi sum hai usko dalde ans ke andar
        if (idx >= arr.size())
        {
            ans.push_back(sum);
            return;
        }

        // recursive case
        // m current element ko sum m le bhi sakta hu and nhi bhi toh pehle m ni le rha hu and then lena hai toh sum m add kiya and leliya.
        helper(idx + 1, arr, sum);
        sum += arr[idx];
        helper(idx + 1, arr, sum);
    }

public:
    vector<int> subsetSums(vector<int> &arr)
    {
        // code here
        helper(0, arr, 0);
        return ans;
    }
};

/*
TC - O(2^n)
SC - O(n) recursion + O(2^n) as jo jo possible subsets hai unka sum toh at max 2^n subsets

*/