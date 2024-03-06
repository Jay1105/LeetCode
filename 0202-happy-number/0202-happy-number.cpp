class Solution {
public:
    bool isHappy(int n) {
        map<long long, int> mp;
        long long num = n;
        bool flag = false;
        
        do
        {
            long long sum = 0;
            while (num)
            {
                long long ld = num % 10;
                ld *= ld;
                sum += ld;
                num /= 10;
            }
            num = sum;
            
            if (num == 1)
                flag = true;
            if (mp[num])
                break;
    
            mp[num] = 1;
        } while (num != 1);
        
        return flag;
    }
};