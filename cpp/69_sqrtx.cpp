class Solution {
    public:
        int mySqrt(int x) {
            long start = 0;
            long end = x;
            long mid = 0;

            if (x == 0 || x == 1)
            {
                return x;
            }

            while (start + 1 < end)
            {
                mid = start + (end - start) / 2;

                if (mid*mid <= x)
                {
                    start = mid;
                }
                else
                {
                    end = mid;
                }
            }

            if (end*end == x)
            {
                return end;
            }
            else
            {
                return start;
            }
        }
};
