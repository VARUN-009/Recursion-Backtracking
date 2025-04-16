// Memoisation
class Solution
{
public:
    int dp[301];
    bool helper(string s, vector<string> &wordDict, int idx)
    {
        // base case
        // tu check karke hi aage badh rha hai and agr tunne saari check karli
        // aur ab string hi khatam ho gayi toh return true ki haa sab mil gayi
        // hai
        if (idx >= s.length())
        {
            return true;
        }

        // not -1 means ki isme either true/false store hua hua hai, bole toh 0
        // ya 1 toh 0 means false and 1 means true
        if (dp[idx] != -1)
        {
            return dp[idx];
        }

        // recursive case
        for (int i = idx; i < s.length(); i++)
        {
            string sample = s.substr(idx, i - idx + 1);
            if (find(wordDict.begin(), wordDict.end(), sample) !=
                    wordDict.end() &&
                helper(s, wordDict, i + 1))
            {
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        memset(dp, -1, sizeof(dp));
        return helper(s, wordDict, 0);
        // unordered_set<string> st(wordDict.begin(), wordDict.end());
    }
};
/*
s ke words todna start kar and sustrings nikalte reh, check kar ki ye hai agr vo
present hai wordDict m and i+1 ke bhi hai toh true, else false; question keh rha

s ko tod and check kar ki jo tod kar words bne vo wordDict m hai ya ni

*/



// TRIES
class Node
{
public:
    char ch;
    bool isTerminal;
    unordered_map<char, Node *> mp;

    Node(char ch)
    {
        this->ch = ch;
        this->isTerminal = false;
    }
};

class Trie
{
public:
    Node *root;

    Trie() { root = new Node('#'); }

    void insert(string word)
    {
        Node *curr = root;
        for (auto ch : word)
        {
            if (curr->mp.find(ch) == curr->mp.end())
            {
                Node *n = new Node(ch);
                curr->mp[ch] = n;
            }
            curr = curr->mp[ch];
        }

        curr->isTerminal = true;
    }

    bool helper(Node *curr, string word, int idx, vector<int> &dp)
    {
        // base case
        // jaise hi string ke length ke equal ab tumne jo str bnayi hai usme na
        // end m ek extra space hogi kyuki tum har baari function call m extra
        // space " " de rahe ho, usko pop_back karo.
        if (idx >= word.length())
        {
            return true;
        }

        if (dp[idx] != -1)
        {
            return dp[idx];
        }

        // recursive case
        Node *ptr = root;
        for (int i = idx; i < word.length(); i++)
        {
            char ch = word[i];
            if (curr->mp.find(ch) == curr->mp.end())
            {
                return dp[idx] = false;
            }
            curr = curr->mp[ch];
            // jab tak terminal na mile add karo, ab terminal mil gya toh uss
            // terminal ko m le bhi sakta hu toh lelo ek baar and baad m jab
            // function return kardega sab toh jo space add ki thi usko remove
            // karo , this is backtracking and then explore other possibilities.
            if (curr->isTerminal)
            {
                if (helper(ptr, word, i + 1, dp))
                {
                    return dp[idx] = true;
                }
            }
        }
        return dp[idx] = false;
    }
};

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        Trie t;
        for (auto word : wordDict)
        {
            t.insert(word);
        }

        Node *curr = t.root;
        vector<int> dp(s.length() + 1, -1);
        return t.helper(curr, s, 0, dp);
    }
};

/*
s ke words todna start kar and sustrings nikalte reh, check kar ki ye hai agr vo
present hai wordDict m and i+1 ke bhi hai toh true, else false; question keh rha

s ko tod and check kar ki jo tod kar words bne vo wordDict m hai ya ni


*/