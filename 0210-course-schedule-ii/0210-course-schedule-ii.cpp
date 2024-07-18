class Solution {
public:

    bool dfsHelp(int i, vector<int> &vis, vector<int> &dfsvis, vector<int> graph[])
    {
        vis[i] = 1;
        dfsvis[i] = 1;
        
        for (auto it: graph[i])
        {
            if (dfsvis[it] == 1)
                return true;
            else if (dfsHelp(it, vis, dfsvis, graph))
                return true;
        }
        
        dfsvis[i] = false;
        return false;
    }
    
    void dfs(int i, vector<int> &vis, stack<int> &st, vector<int> graph[])
    {
        vis[i] = 1;
        
        for (auto it: graph[i])
        {
            if (vis[it] == 0)
                dfs(it, vis, st, graph);
        }
        
        st.push(i);
    }
        
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> graph[numCourses];
        for (int i = 0; i < prerequisites.size(); i++)
        {
            vector<int> tp = prerequisites[i];
            graph[tp[1]].push_back(tp[0]);
        }
        
        vector<int> vis(numCourses);
        vector<int> dfsvis(numCourses);
        
        bool flag = false;
        
        for (int i = 0; i < numCourses; i++)
        {
            if (vis[i] == 0)
            {
                if (dfsHelp(i, vis, dfsvis, graph))
                {
                    flag = true;
                    break;
                }
            }
        }
        
        vector<int> ans;
        
        if (!flag)
        {
            stack<int> st;
            vis.clear();
            vis.resize(numCourses, 0);
            
            for (int i = 0; i < numCourses; i++)
            {
                if (vis[i] == 0)
                    dfs(i, vis, st, graph);
            }
            
            while (!st.empty())
            {
                ans.push_back(st.top());
                st.pop();
            }
        }
        return ans;
    }
};