class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int size1 = nums1.length;
        int size2 = nums2.length;
        
        int mid = size1 + size2;
        
        if (mid % 2 != 0)
        {
            return (double)findK(nums1, 0, size1 - 1, nums2, 0, size2 - 1, mid / 2 + 1);
        }
        else
        {
            int result1 = findK(nums1, 0, size1 - 1, nums2, 0, size2 - 1, mid / 2);
            System.out.println("result1 : " + result1);
            int result2 = findK(nums1, 0, size1 - 1, nums2, 0, size2 - 1, mid /2 + 1);
            System.out.println("result2 : " + result2);
            return (double)(result1 + result2)/2;            
        }
    }


    public static int findK(int[] num1, int start1, int end1, int[] num2, int start2, int end2, int k) {
        System.out.printf("start1, %d, end1, %d, start2, %d, end2, %d, k , %d\n", start1, end1, start2, end2, k);
        int m = end1 - start1 + 1;
        int n = end2 - start2 + 1;
        
        if (m > n)
        {
            return findK(num2, start2, end2, num1, start1, end1, k);
        }
        
        if (m == 0)
        {
            System.out.println("check point return");
            return num2[k - 1];
        }
        
        if (k == 1)
        {
            return Math.min(num1[start1], num2[start2]);
        }
        
        int part1 = Math.min(k/2, m);
        int part2 = k - part1;
        
        System.out.println(start1 + part1 - 1);
        System.out.println(start2 + part2 - 1);
        
        if (num1[start1 + part1 - 1] < num2[start2 + part2 - 1])
        {
            return findK(num1, start1 + part1, end1, num2, start2, end2, k - part1);
        }
        else
        {
            return findK(num1, start1, end1, num2, start2 + part2, end2, k - part2);
        }
        
        
    }
    
}