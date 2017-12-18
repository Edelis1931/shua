class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {

        if (matrix.length == 0 || matrix[0].length == 0)
        {
            return false;
        }

        // let's find which row first
        int start = 0;
        int end = matrix.length - 1;
        int mid = 0;
        int row = 0;
        int col = 0;

        boolean result = true;

        while (start + 1 < end)
        {
            mid = start + (end - start) / 2;

            if (target <= matrix[mid][0])
            {
                end = mid;
            }
            else
            {
                start = mid;
            }
        }

        if (target < matrix[end][0])
        {
            row = start;
        }
        else
        {
            row = end;
        }

        System.out.println("the row is : " + row);

        // now let's find which col
        start = 0;
        end = matrix[0].length - 1;

        while (start + 1 < end)
        {
            mid = start + (end - start) / 2;

            if (target <= matrix[row][mid])
            {
                end = mid;
            }
            else
            {
                start = mid;
            }
        }

        if (target == matrix[row][end])
        {
            col = end;
        }
        else if (target == matrix[row][start])
        {
            col = start;
        }
        else
        {
            result = false;
        }

        return result;
    }
}
