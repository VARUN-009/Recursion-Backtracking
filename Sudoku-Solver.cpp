class Solution
{
private:
    bool check(int row, int col, char ch, vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {

            // same column m na ho
            if (board[i][col] == ch)
            {
                return false;
            }

            // same row m na ho
            if (board[row][i] == ch)
            {
                return false;
            }

            // check in a 3*3 matrix
            // 012, 345, 678, ye banege so row/3 se 0 1 2 ki value aayegi ki row m 3 m se konse box m hai and same with column. 3 se multiply ki aage jaa sake like 2 value aayi means 3rd level so 3*2 6 so 6th index se start hoga. i/3 in row as hume same row m 3 baar rehna hai and i%3 in col as hume har baar col change karna hai.
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch)
            {
                return false;
            }
        }

        return true;
    }
    bool helper(vector<vector<char>> &board)
    {
        // base case
        // already covered in recursive case as we are only moving from 0 to 9 so m kabhi aage ni jaunga is se and meine ek ka check kiya and aage ko bola ki bhai recursion bta, true means abhi jo pur kiya sahi kiya so return true else backtrack same karo and kuch aur lagao. 

        // recursive case
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {

                if (board[i][j] == '.')
                {
                    for (char digit = '1'; digit <= '9'; digit++)
                    {
                        if (check(i, j, digit, board))
                        {
                            // abhi lagado 
                            board[i][j] = digit;

                            // aage se check karo abhi ye toh fix kardiya . toh ab next time m iske aage wala koi . consider hoga
                            if (helper(board))
                            {
                                return true;
                            }

                            // answer ni mila means galat lagaya toh backtrack
                            board[i][j] = '.';
                        }
                    }

                    // agr 1-9 tak kuch bhi ni laga paa rha means false kyuki laga hi ni sakta na toh that's why.
                    return false;
                }
            }
        }

        // agr sab sahi rha toh return true ki haa board bnke taiyaar hai 
        return true;
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        helper(board);
    }
};