class Solution {
    public int search(int[] A, int target) {
        int start = 0;
        int end = A.length - 1;
        
        if (end == -1)
        {
            return -1;
        }
        
        int mid = 0;
        
        while (start + 1 < end)
        {
            mid = start + (end - start) / 2;
            
            if (A[start] < A[mid]){
                if (A[start] <= target && target <= A[mid])
                {
                    end = mid;
                }
                else
                {
                    start = mid;
                }
            }
            else
            {
                if (A[mid] <= target && target <= A[end])
                {
                    start = mid;
                }
                else
                {
                    end = mid;
                }
            }
            
        }
        
        System.out.println("start" + start);
        System.out.println("end" + end);
        
        if (A[start] == target)
        {
            return start;
        }
        else if(A[end] == target)
        {
            return end;
        }
        else
        {
            return -1;
        }
    }
}