class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int res = n;
        
        int icnt = 1, dcnt = 0;
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                if (i - 2 >= 0 && ratings[i - 1] < ratings[i - 2])
                    icnt = 1;
                res += icnt;
                icnt += 1;
                dcnt = 0;
            }
            else if (ratings[i] == ratings[i - 1])
            {
                icnt = 1;
                dcnt = 0;
            }
            else
            {
                if (icnt > 1)
                    icnt--;
                else
                    res += 1;
                res += dcnt;
                dcnt += 1;
            }
        }
        return res;
    }
};