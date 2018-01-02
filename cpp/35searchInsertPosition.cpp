class Solution {
	public:
		int searchInsert(vector<int>& nums, int target) {
			int start = 0;
			int end = nums.size() - 1;
			if (end == -1)
			{
				return 0;
			}


			int mid = start + (end - start) / 2;

			while (start + 1 < end)
			{
				mid = start + (end - start) / 2;

				if (nums.at(mid) < target)
				{
					start = mid;
				}
				else
				{
					end = mid;
				}
			}

			std::cout << "start:" << start << endl; 
			std::cout << "end:" << end << endl;

			//now we have the start and the end
			if (nums.at(end) == target)
			{
				return end;
			}
			else if (nums.at(start) == target)
			{
				return start;
			}
			else if (target < nums.at(start))
			{
				return 0;
			}
			else if (target > nums.at(end))
			{
				return end + 1;
			}
			else
			{
				return start + 1;
			}
		}
};
