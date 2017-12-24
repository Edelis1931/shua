class Solution {
    public double findMedianSortedArrays(intp[] num1, int[] nums2) {
    }

    public findK(int[] a, int aStart, int aEnd, int[] b, int bStart, int bEnd, int k){
        int aLength = aEnd - aStart + 1;
        int bLength = bEnd - bStart + 1;

        if (aLenth > bLength){
            return findK(b, bStart, bEnd, a, aStart, aEnd, k);
        }

        int half = Math.min(k/2, aLength);
        int newK = k - half;



    }
}
