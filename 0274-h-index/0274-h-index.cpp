class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> freq(1001, 0);
        
        for (int i = 0; i < n; i++)
            freq[citations[i]]++;
        for (int i = 999; i >= 0; i--)
            freq[i] += freq[i + 1];
        
        int mx = 0;
        for (int i = 1000; i >= 0; i--)
        {
            if (freq[i] >= i)
            {
                mx = i;
                break;
            }
        }
        return mx;
    }
};