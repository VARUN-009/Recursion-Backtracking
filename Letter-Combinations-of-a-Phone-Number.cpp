class Solution
{
private:
    vector<string> letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    void helper(string digits, string output, int idx)
    {
        // base case
        if (idx >= digits.size())
        {
            ans.push_back(output);
            return;
        }

        // recursive case
        // meine ek character liya then aage wale number ke liye gya and the uska ek ek karke character liya and then aage wale ke liye gya and as soon as I reach end, abhi tak ki jo bhi meri string hai ans ka part bna do.
        int num = digits[idx] - '0';
        string str = letters[num];
        for (int j = 0; j < str.length(); j++)
        {
            output.push_back(str[j]);
            helper(digits, output, idx + 1);
            output.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        // agr koi hai hi ni toh direct empty array return 
        if (digits.length() == 0)
        {
            return ans;
        }
        helper(digits, "", 0);
        return ans;
    }
};