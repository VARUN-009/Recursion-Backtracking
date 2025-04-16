class Solution
{
public:
    string getPermutation(int n, int k)
    {
        vector<int> vec;
        // calculating factorial for n-1 as every block will have (n-1)! permutations
        int fact = 1;
        for (int i = 1; i < n; i++)
        {
            fact *= i;
            vec.push_back(i);
        }
        vec.push_back(n);
        // array will be [1 2 3 4]

        // Since we will be working on 0th based indexing so 14th permutation will actually be 13th one since there will also be a 0th permutation.
        k = k - 1;

        // since the array has 4 numbers so first we'll fix the first number then we'll fix the second number and then so on... till the array is empty
        // In permutaions, the digits can't be repeated so after fixing a digit remove it from the array.

        string ans = "";
        while (true)
        {
            ans += to_string(vec[k / fact]);
            vec.erase(vec.begin() + k / fact);

            if (vec.size() == 0)
            {
                break;
            }

            // to find the remaining in that block
            k = k % fact;
            fact = fact / vec.size();
        }
        return ans;
    }
};