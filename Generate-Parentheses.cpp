class Solution
{
private:
    vector<string> ans;
    void helper(int left, int right, string str)
    {
        // base case
        // jab mere dono hi khatam ho gaye toh tab matlab meine use karliye hai dono ko toh answer mil gya hai so jo string aayi hai usko answer m lo
        if (left == 0 && right == 0)
        {
            ans.push_back(str);
            return;
        }

        // recursive case
        // agr ( hai mera toh lo usko and left-- and agr ) hai toh lo usko and right--
        if (left > 0)
            helper(left - 1, right, str + "(");
        // isme dekhna padega ki right wale jyada hai na as agr same ho toh tu pehle left hi lagayega cannot start with ) so ek bhi ) laga diya means right wale jyada so then you can do right. 
        if (right > left)
            helper(left, right - 1, str + ")");
    }

public:
    vector<string> generateParenthesis(int n)
    {
        helper(n, n, "");
        return ans;
    }
};