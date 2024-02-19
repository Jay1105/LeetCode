class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        int arr[7] = {1000, 500, 100, 50, 10, 5, 1};
        char drr[7] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        
        for (int i = 0; i < 7; i++)
        {
            int digit = num / arr[i];
            
            if (digit == 0)
                continue;
            
            int tp = digit * arr[i];

            if (num == 4)
            {
                ans += "IV";
                num -= 4;
            }
            else if (num == 9)
            {
                ans += "IX";
                num -= 9;
            }
            else if (num / 10 == 4)
            {
                ans += "XL";
                num -= 40;
            }
            else if (num / 10 == 9)
            {
                ans += "XC";
                num -= 90;
            }
            else if (num / 100 == 4)
            {
                ans += "CD";
                num -= 400;
            }   
            else if (num / 100 == 9)
            {
                ans += "CM";
                num -= 900;
            }
            else
            {
                while (digit--)
                    ans += drr[i];
                num -= tp;
            }
        }
        return ans;
    }
};
