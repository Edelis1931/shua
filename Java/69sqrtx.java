class Solution {
    public int mySqrt(int x) {

        if (x == 1){
            return 1;
        }

        long start = 1;
        long mid = 0;
        long end = x;

        while (start + 1 < end)
        {
            mid = start + (end - start) / 2;
            System.out.println("mid is: " + mid);

            if (mid*mid > x)
            {
                end = mid;
            }
            else
            {
                start = mid;
            }
        }

        System.out.println("start is: " + start);
        System.out.println("end is: " + end);

        if (end*end == x)
        {
            return (int)end;
        }
        else
        {
            return (int)start;
        }
    }
}
