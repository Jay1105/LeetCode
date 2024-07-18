class Solution {
public:

    bool dfsHelp(int i, vector<int> &vis, vector<int> &dfsvis, vector<int> adj[])
    {
        vis[i] = 1;
        dfsvis[i] = 1;

        for (auto it : adj[i])
        {
            if (vis[it] == 0)
            {
                if (dfsHelp(it, vis, dfsvis, adj))
                {
                    return true;
                }
            }
            else if (dfsvis[it] == 1)
            {
                return true;
            }
        }

        dfsvis[i] = 0;

        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> graph[numCourses];
        map<string, int> mp;
        
        for (int i = 0; i < prerequisites.size(); i++)
        {
            vector<int> tp = prerequisites[i];
            graph[tp[0]].push_back(tp[1]);
            
            string temp = to_string(tp[0]) + "-" + to_string(tp[1]);
            mp[temp] = 1;
        }
                
        for (int i = 0; i < numCourses; i++)
        {
            for (int j = 0; j < graph[i].size(); j++)
            {
                string temp = to_string(graph[i][j]) + "-" + to_string(i);
                
                if (mp[temp])
                    return false;
            }
        }
        
        vector<int> vis(numCourses, 0);
        vector<int> dfsvis(numCourses, 0);
        
        for (int i = 0; i < numCourses; i++)
        {
            if (!vis[i])
            {
                if (dfsHelp(i, vis, dfsvis, graph))
                    return false;
            }
        }
        
        return true;
    }
};