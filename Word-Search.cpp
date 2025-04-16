class Solution
{
public:
    bool searchWord(vector<vector<char>> &board, string &word, int i, int j,
                    int n, int m, int k)
    {
        // base case
        // if all the words are scanned, means we have found the answer, so
        // return true
        if (k == word.size())
        {
            return true;
        }

        // if you gave gone out of the matrix, means you can't find the answer.
        // so return false;
        if (i == -1 || j == -1 || i == n || j == m)
        {
            return false;
        }

        // means if the current character of the board is not equal to current
        // character of the word, so just return false as this is not the
        // character you are looking for.
        if (board[i][j] != word[k])
        {
            return false;
        }
        // This will be same as board[i][j]=='#'.

        // recursive case
        // board[i][j]==word[k], because from the exist function we are only
        // calling the searchWord when board[i][j]==word[0], means we have found
        // the starting character so fix that character so that it can't be
        // compared again.
        board[i][j] = '#';

        // now we have 4 possibilities, we can move up, left, right and bottom.
        // In either of the direction we can move, so start moving, it's your
        // choice in which direction we have to move first.

        // now move in the right direction, see whether moving in that direction
        // we have found the answer or not.
        if (searchWord(board, word, i, j + 1, n, m, k + 1))
        {
            return true;
        }

        // now move in the left direction, see whether moving in that direction
        // we have found the answer or not.
        if (searchWord(board, word, i, j - 1, n, m, k + 1))
        {
            return true;
        }

        // now move in the down direction, see whether moving in that direction
        // we have found the answer or not.
        if (searchWord(board, word, i + 1, j, n, m, k + 1))
        {
            return true;
        }

        // now move in the top direction, see whether moving in that direction
        // we have found the answer or not.
        if (searchWord(board, word, i - 1, j, n, m, k + 1))
        {
            return true;
        }

        // out of all the possibilities, we haven't found the answer, to
        // backtrack it, means the board[i][j] you have set to '#', reset it to
        // default basically we are calling the calls for k+1, if that calls
        // return false, then ultimately we are at word[k], so make that to
        // word[k], so that it can be set to default and we'll backtrack, move
        // backward.
        board[i][j] = word[k];
        return false;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0] and
                    searchWord(board, word, i, j, n, m, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
// If we have to search the word, then we'll start from the first alphabet of
// the word, if same then we'll move forward. So first found, which character is
// equal to the word[0], then for that call the searchWord function. if Not then
// keep searching. order of base cases matter alot, first base case will be that
// we have found the word, as k will be equal to word.size(). means we have got
// all the characters before it.