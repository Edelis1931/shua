import java.util.*;

class Solution {
    public int[] twoSum(int[] nums, int target) {

        Hashtable<Integer, Integer> myHash = new Hashtable<Integer, Integer>();
        int size = nums.length;
        int first = 0;
        int second = 0;

        for (int i = 0; i < size; i++)
        {
            //出错点：我们放入hashtable的可以是target - 当前数，也可以是当前数，但^1,^2,^3,^4四个位置的key必须一致
            //所以比较方便的做法是target - nums[i],然后查找nums[i]
            if (!myHash.containsKey(nums[i]/*target - nums[i]*/)) //^1
            {
                myHash.put(target - nums[i], i);
            }
            else
            {
                //出错点：我们比较的是序号，所以是i和myHash.get(nums[i])，而不是nums[i]和myHash.get(nums[i])
                first = Math.min(i /*nums[i]*/, myHash.get(nums[i])); //^3
                second = Math.max(i /*nums[i]*/, myHash.get(nums[i])); //^4
                break;
            }
        }


        int[] result = {first, second};
        return result;
    }
}
