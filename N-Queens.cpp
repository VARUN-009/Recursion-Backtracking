class Solution
{
public:
    vector<vector<string>> result;
    bool isSafeToPut(vector<string> &ans, int i, int j, int n)
    {
        // Check row and column
        for (int k = 0; k < n; k++)
        {
            if (ans[k][j] == 'Q')
            {
                return false;
            }
        }

        // for(int c=0; c<n; i++) {
        //     if(ans[i][c]=='Q') {
        //         return false;
        //     }
        // }

        // Check upper right diagonal
        int l = i, m = j;
        while (i >= 0 and j < n)
        {
            if (ans[i][j] == 'Q')
            {
                return false;
            }
            i--;
            j++;
        }
        // Check upper left diagonal
        i = l, j = m;
        while (i >= 0 and j >= 0)
        {
            if (ans[i][j] == 'Q')
            {
                return false;
            }
            i--;
            j--;
        }

        return true;
    }

    void NQueen(vector<string> &ans, int i, int n)
    {
        // base case
        if (i == n)
        {
            result.push_back(ans);
            return;
        }

        // recursive case
        for (int j = 0; j < n; j++)
        {
            if (isSafeToPut(ans, i, j, n) == true)
            {
                ans[i][j] = 'Q';
                NQueen(ans, i + 1, n);
                // if(remainingBoard == true) {
                //     return true;
                // }
                ans[i][j] = '.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> ans(n, string(n, '.'));
        NQueen(ans, 0, n);
        return result;
    }
};