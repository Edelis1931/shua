class Solution {
    public int findMin(int[] nums) {
        int start = 0;
        int end = nums.length - 1;
        
        if (end == -1)
        {
            return 0;
        }

        int target = nums[end];
        
        int mid = 0;
        
        while (start + 1 < end)
        {
            mid = start + (end - start) / 2;
            
            if (nums[mid] < target)
            {
                end = mid;
            }
            else
            {
                start = mid;
            }
        }
        
        System.out.println("start:" + nums[start]);
        System.out.println("end:" + nums[end]);
        
        if (nums[start] <= target)
        {
            return nums[start];
        }
        else
        {
            return nums[end];
        }
    }
}