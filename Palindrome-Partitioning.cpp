class Solution
{
public:
    bool checkPalindrome(string &s, int start, int end)
    {
        while (start <= end)
        {
            if (s[start] != s[end])
            {
                return false;
            }
            start++;
            end--;
        }

        return true;
    }

    void helper(string s, vector<string> ans, vector<vector<string>> &result,
                int idx)
    {
        // base case
        if (idx >= s.length())
        {
            result.push_back(ans);
            return;
        }

        // recursive case
        for (int i = idx; i < s.length(); i++)
        {
            if (checkPalindrome(s, idx, i))
            {
                ans.push_back(s.substr(idx, i - idx + 1));
                helper(s, ans, result, i + 1);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> result;
        vector<string> ans;
        helper(s, ans, result, 0);
        return result;
    }
};

/*
Twist is that ki meine pehle ek liya agr vo hai toh uske aage se meine recursion
ko bola ki bhai tu bta aage se, and phir loop m character m add karte raha ki
aur include karo ab, kyuki ek baar se answer aagya na. backtracking hai simple
bss lelo and then baad m htado aur explore karne ke liye.

*/
