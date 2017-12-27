class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        //counter cases
        if (matrix.size() == 0)
        {
            return false;
        }
        
        if (matrix.at(0).size() == 0)
        {
            return false;
        }
        
        
        //let's find which row first
        int start = 0;
        int end = matrix.size() - 1;
        int mid = 0;
        int row = 0;
        int col = 0;
        
        while (start + 1 < end)
        {
            mid = start + (end - start) / 2;
            
            if (target < matrix.at(mid).at(0))
            {
                end = mid;
            }
            else
            {
                start = mid;
            }
        }
        
        if (target < matrix.at(end).at(0))
        {
            row = start;
        }
        else
        {
            row = end;
        }
        
        std::cout<< "row:" << row << std::endl;
        
        //let's find which col now
        start = 0;
        end = matrix.at(0).size() - 1;
        mid = 0;
        
        while (start + 1 < end)
        {
            mid = start + (end - start) / 2;
            
            if (target < matrix.at(row).at(mid))
            {
                end = mid;
            }
            else
            {
                start = mid;
            }
        }
        
        std::cout << "start:" << start << std::endl;
        std::cout << "end:" << end << std::endl;
        
        if (matrix.at(row).at(start) == target || matrix.at(row).at(end) == target)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

};