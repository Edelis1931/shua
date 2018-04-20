class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int start = 0;
            int end = nums.size() - 1;
            if (end == -1)
            {
                return -1;
            }

            int mid = 0;
            int last = nums.back();

            while(start + 1 < end)
            {
                mid = start + (end - start) / 2;

                if (nums.at(mid) > last)
                    if (nums.at(start) <= target && target <= nums.at(mid))
                    {
                        end = mid;
                    }
                    else
                    {
                        start = mid;
                    }
                else
                {
                    if (nums.at(mid) <= target && target <= nums.at(end))
                    {
                        start = mid;
                    }
                    else
                    {
                        end = mid;
                    }
                }
            }

            if (nums.at(start) == target)
            {
                return start;
            }
            else if(nums.at(end) == target)
            {
                return end;
            }
            else
            {
                return -1;
            }
        }
};
