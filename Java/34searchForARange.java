class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] result = {-1, -1};

        if (nums.length == 0) return result;

        int start = 0;
        int end = nums.length - 1;
        int mid = 0;

        //find the left bound
        while (start + 1 < end)
        {
            mid = start + (end - start)/2;
            if (nums[mid] < target)
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }
        //now we should have only 2 result in nums
        //出错点：在找左bound的时候必须先看star，再看end
        //防止出现[8,8]的情况
        if (nums[start] == target)
        {
            result[0] = start;
        }
        else if (nums[end] == target)
        {
            result[0] = end;
        }
        else
        {
            return result;
        }

        //now find the right
        start = 0;
        end = nums.length - 1;

        while (start + 1 < end)
        {
            mid = start + (end - start)/2;
            if (nums[mid] > target)
            {
                end = mid;
            }
            else
            {
                start = mid;
            }
        }
        //now we should have only two elements in nums
        //出错点：在找右bound的时候必须先看end，再看start
        if (nums[end] == target)
        {
            result[1] = end;
        }
        else if (nums[start] == target)
        {
            result[1] = start;
        }
        else
        {
            return result;
        }

        return result;

    }
}
