class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> ans;
        int i = 0;

        while (i < words.size())
        {
            int charCnt = words[i].size();
            int spaceCnt = 0;
            int j = i + 1;

            while (j < words.size() && (charCnt + spaceCnt + 1 + words[j].size() <= maxWidth))
            {
                charCnt += words[j].size();
                spaceCnt++;
                j++;
            }

            int rem = maxWidth - charCnt;
            int equalDistribute = (spaceCnt == 0) ? 0 : rem / spaceCnt;
            int extraDistribute = (spaceCnt == 0) ? 0 : rem % spaceCnt;

            if (j == words.size())
            {
                equalDistribute = 1;
                extraDistribute = 0;
            }

            string temp;
            for (int k = i; k < j; k++)
            {
                temp += words[k];

                for (int tp = 0; tp < equalDistribute; tp++)
                    temp.push_back(' ');

                if (extraDistribute)
                {
                    temp.push_back(' ');
                    extraDistribute--;
                }
            }
            while (temp.length() < maxWidth)
                temp.push_back(' ');
            
            string s = temp.substr(0, maxWidth);

            ans.push_back(s);

            i = j;
        }

        return ans;
    }
};