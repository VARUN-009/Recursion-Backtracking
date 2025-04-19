class Solution
{
private:
    bool possible(int node, int col, vector<int> &colors, vector<vector<int>> &adj)
    {
        // agr koi bhi child same color ka hai means you cannot color it with col so return false.
        for (auto child : adj[node])
        {
            if (colors[child] == col)
            {
                return false;
            }
        }

        return true;
    }
    bool helper(int node, vector<int> &colors, int m, vector<vector<int>> &adj, int n)
    {
        // base case
        // agr at the end tunne har node ko color karidya means sab nodes poori toh it means you can color it.
        if (node == n)
        {
            return true;
        }

        // recursive case
        // possible colors kya hai 1 to m lelo and colors ko number se represent karlo.
        for (int col = 1; col <= m; col++)
        {
            if (possible(node, col, colors, adj))
            {
                // abhi ye color lagao and aage se check karo agr sahi hai true aarha hai means I can color it else backtrack karo dusra color lagao and then check karo.
                colors[node] = col;

                if (helper(node + 1, colors, m, adj, n))
                {
                    return true;
                }

                // backtrack - ki bhai jo pehle lagayaa tha uss se toh answer ni aaya dusra color lagao ab par pehle isko pehle ki tarah kardo
                colors[node] = 0;
            }
        }

        // If saari koshish karne ke baad bhi color ni hua toh bhai return false
        return false;
    }

public:
    bool graphColoring(int v, vector<pair<int, int>> &edges, int m)
    {
        // code here
        // v nodes ke liye color store karne ke liye
        vector<int> colors(v, 0);

        // to make our own adjacency matrix
        vector<vector<int>> adj(v);
        for (auto p : edges)
        {
            adj[p.first].push_back(p.second);
            adj[p.second].push_back(p.first);
        }

        return helper(0, colors, m, adj, v);
    }
};
/*
TC - N nodes and for each node, m colors are there so O(m^n) so (choices ^ total elements) 
SC - O(n) colors + O(n) recursion + O(V+E) for adjacency matrix basically total edges are E, it's not like every node is connected with every node.
*/