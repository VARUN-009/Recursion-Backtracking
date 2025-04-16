// RECURSION BACKTRACKING
class Solution
{
public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
    }
};

// TRIE + BACKTRACKING
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

    void helper(Node *curr, string word, int idx, string str,
                vector<string> &ans)
    {
        // base case
        // jaise hi string ke length ke equal ab tumne jo str bnayi hai usme na
        // end m ek extra space hogi kyuki tum har baari function call m extra
        // space " " de rahe ho, usko pop_back karo.
        if (idx >= word.length())
        {
            str.pop_back();
            ans.push_back(str);
            return;
        }

        // recursive case
        Node *ptr = root;
        for (int i = idx; i < word.length(); i++)
        {
            char ch = word[i];
            if (curr->mp.find(ch) == curr->mp.end())
            {
                return;
            }
            str.push_back(ch);
            curr = curr->mp[ch];
            // jab tak terminal na mile add karo, ab terminal mil gya toh uss
            // terminal ko m le bhi sakta hu toh lelo ek baar and baad m jab
            // function return kardega sab toh jo space add ki thi usko remove
            // karo , this is backtracking and then explore other possibilities.
            if (curr->isTerminal)
            {
                str += " ";
                helper(ptr, word, i + 1, str, ans);
                str.pop_back(); // backtracking, jo space dali vo remove
            }
        }
        return;
    }
};

class Solution
{
public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        Trie t;
        for (auto word : wordDict)
        {
            t.insert(word);
        }

        Node *curr = t.root;
        vector<string> ans;
        t.helper(curr, s, 0, "", ans);
        return ans;
    }
};
/*
Logic is same like word break, usme jaise hi terminal milega, m phirse start se
count karunga and agr m string ke end tak pahoch gya means ki haa ye string bn
sakti hai words ke combination se, so I'll return true, isme bss string m store
karte rahege and jaise hi end m pahoche uss string ko ans m push.

*/