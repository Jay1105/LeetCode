class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int n = strs.size();
        int low = 1;
        int high = 200;
        
        if (n == 1)
            return strs[0];
        
        for (int i = 0; i < n; i++)
        {
            if (strs[i].size() < high)
                high = strs[i].size();
        }
                
        while (low <= high)
        {
            int mid = (low + high) / 2;
            string temp = strs[0].substr(0, mid);

            bool flag = true;
            for (int i = 1; i < n; i++)
            {
                if (strs[i].substr(0, mid) != temp)
                {
                    flag = false;
                    break;
                }
            }
            cout << temp << "\n";
            
            if (flag)
            {
                ans = temp;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;
    }
};