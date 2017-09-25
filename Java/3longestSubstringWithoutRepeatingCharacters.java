//reference:
//http://bangbingsyb.blogspot.ca/2014/11/leetcode-longest-substring-without.html

//假设有abcdddd
//     012345
//思路：把每个<字母,位置>放入一个hashtable，
//所以上来应该是:a0 b1 c2 d3
//如果发现有相同的字母d4, 就把hashtable里所有d3之前的内容都清掉，然后把d3设成start

import java.util.*;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        
        //abcbbb
        //012345
        
        Hashtable<Character, Integer> myHash = new Hashtable<Character, Integer>();
        int maxLen = 0;
        int start = 0;
        int curLen = 0;
        int size = s.length();
        
        for (int i = 0; i < size; i++)
        {
            char curLetter = s.charAt(i);
            if (myHash.containsKey(curLetter))
            {
                //假设目前是abcd,进来一个d,这里之所以清到d之前而不是d,是因为要留着d设置新的start point
                for (int j = start; j < myHash.get(curLetter); j++) //^1
                {
                    myHash.remove(s.charAt(j)/*curLetter*/);
                }
                //必须把前面那个for循环走完才能update start point，所以^1的地方必须是j < myHash.get(curLetter)，而不能是j <= myHash.get(curLetter)
                start = myHash.get(curLetter) + 1;
                curLen = i - myHash.get(curLetter);
                //这个会replace现有的key,所以在设置完start point之后再remove
                myHash.put(curLetter, i);
            }
            else
            {
                myHash.put(curLetter, i);
                curLen += 1;
            }
            
            maxLen = Math.max(maxLen, curLen);
        }
        
        return maxLen;
        
    }
}