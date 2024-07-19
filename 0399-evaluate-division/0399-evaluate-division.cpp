class Solution {
public:
    double dfsHelp(string src, string dest, unordered_set<string> &vis, unordered_map<string, unordered_map<string, double>> graph)
    {
        if (graph.find(src) == graph.end() || graph.find(dest) == graph.end())
            return -1.0;
        if (src == dest)
            return 1.0;
        
        vis.insert(src);
        for (auto neighbour: graph[src])
        {
            if (vis.find(neighbour.first) != vis.end())
                continue;
            
            double res = dfsHelp(neighbour.first, dest, vis, graph);
            
            if (res != -1.0)
                return (res * neighbour.second);
        }
        return -1.0;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        unordered_map<string, unordered_map<string, double>> graph;
        for (int i = 0; i < equations.size(); i++)
        {
            string a = equations[i][0];
            string b = equations[i][1];
            
            graph[a][b] = values[i];
            graph[b][a] = 1.0 / values[i];
        }
        
        vector<double> ans;
        for (auto q: queries)
        {
            string a = q[0];
            string b = q[1];
            
            unordered_set<string> vis;
            ans.push_back(dfsHelp(a, b, vis, graph));
        }
        
        return ans;
    }
};