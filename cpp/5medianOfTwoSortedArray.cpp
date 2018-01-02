class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        
        int totalSize = size1 + size2;
        
        if (totalSize % 2 == 0)
        {
            double result1 = findK(nums1, 0, size1 - 1, nums2, 0, size2 - 1, totalSize / 2);
            double result2 = findK(nums1, 0, size1 - 1, nums2, 0, size2 - 1, totalSize / 2 + 1);
            return (result1 + result2) / 2;
        }
        else
        {
            double result = findK(nums1, 0, size1 - 1, nums2, 0, size2 - 1, totalSize / 2 + 1);
            return result;
        }
    }
    
    static double findK(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2, int k)
    {
        int m = end1 - start1 + 1;
        int n = end2 - start2 + 1;
        
        if (m > n)
        {
            return findK(nums2, start2, end2, nums1, start1, end1, k);
        }
        if (m == 0)
        {
            return nums2.at(k - 1);
        }
        if (k == 1)
        {
            return std::min(nums1.at(start1), nums2.at(start2));
        }
        
        int part1 = std::min(k/2, m);
        int part2 = k - part1;
        
        if (nums1.at(start1 + part1 - 1) < nums2.at(start2 + part2 - 1))
        {
            return findK(nums1, start1 + part1, end1, nums2, start2, end2, k - part1);
        }
        else
        {
            return findK(nums1, start1, end1, nums2, start2 + part2, end2, k - part2);
        }
    }
        
};