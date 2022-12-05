class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ar(nums1.size());
        int id1 = 0, id2 = 0, id = 0;
        
        while (id1 < m && id2 < n)
        {
            if (nums1[id1] <= nums2[id2])
            {
                ar[id] = nums1[id1];
                id1++;
            }
            else
            {
                ar[id] = nums2[id2];
                id2++;
            }
            id++;
        }
        while (id1 < m)
        {
            ar[id] = nums1[id1];
            id++, id1++;
        }
        while (id2 < n)
        {
            ar[id] = nums2[id2];
            id++, id2++;
        }
        
        for (int i = 0; i < m + n; i++)
        {
            nums1[i] = ar[i];
        }
    }
};