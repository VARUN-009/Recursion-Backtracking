class Solution
{
private:
    vector<string> ans;
    void helper(int row, int col, int n, vector<vector<int>> &mat, string str)
    {
        // base case
        // agr bahar gaya cell se ya vo 0 hai rasta ni hai toh return;
        if (row < 0 || row >= n || col < 0 || col >= n || mat[row][col] == 0)
        {
            return;
        }

        // end m pahoch gya toh jo bhi abhi tak answer aaya lele
        if (row == n - 1 && col == n - 1)
        {
            ans.push_back(str);
            return;
        }

        // recursive case
        // pehle toh isko 0 kar as isme tu ek baar aagya hai but but, saare possible paths dekhne ke baad isko 1 karna padega kyuki kya pta dusre kisi path m bhi ye cell aarha ho toh usme count karne ke liye
        mat[row][col] = 0;
        helper(row + 1, col, n, mat, str + "D");
        helper(row, col + 1, n, mat, str + "R");
        helper(row - 1, col, n, mat, str + "U");
        helper(row, col - 1, n, mat, str + "L");
        mat[row][col] = 1;
    }

public:
    vector<string> findPath(vector<vector<int>> &mat)
    {
        // code here
        int n = mat.size();
        helper(0, 0, n, mat, "");
        return ans;
    }
};

/*
Time Complexity: O(4^(n^2))
Why?
At each of the n*n cells, you might try up to 4 directions.

So worst-case tree size is up to 4^(n^2) recursive calls.
Space Complexity - O(n^2) (due to recursion stack and visited matrix)
*/
