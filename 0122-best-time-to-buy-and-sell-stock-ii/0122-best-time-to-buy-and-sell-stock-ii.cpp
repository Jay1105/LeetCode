class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = INT_MAX;
        int profit = 0;
        int n = prices.size();
        
        for (int i = 0; i < n; i++)
        {
            if (prices[i] < mn)
                mn = prices[i];
            else if (prices[i] - mn > 0)
            {
                profit += prices[i] - mn;
                mn = prices[i];
            }
        }
        return profit;
    }
};