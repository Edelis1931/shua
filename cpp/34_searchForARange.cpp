class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> result;
        result.push_back(-1);
        result.push_back(-1);
        if (!size)
        {
            return result;
        }
        
        //try to find the left bound
        int start = 0;
        int end = size - 1;
        int mid = 0;
        
        while (start + 1 < end)
        {
            mid = start + (end - start) / 2;
            if (nums[mid] < target)
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }
        if (nums[start] == target)
        {
            result.at(0) = start;
        }
        else if (nums[end] == target)
        {
            result.at(0) = end;
        }
        else
        {
            return result;
        }
        
        //try to find the right bound
        start = 0;
        end = size - 1;
        mid = 0;
        
        while (start + 1 < end)
        {
            mid = start + (end - start) / 2;
            if (nums[mid] > target)
            {
                end = mid;
            }
            else
            {
                start = mid;
            }
        }
        if (nums[end] == target)
        {
            result.at(1) = end;
        }
        else if (nums[start] == target)
        {
            result.at(1) = start;
        }
        else
        {
            return result;
        }
        
    return result;
        
    }
};