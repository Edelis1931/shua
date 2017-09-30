#include <algorithm>

using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            unordered_map<char, int> myHash;
            int curLen = 0;
            int start = 0;
            int maxLen = 0;

            for (int i = 0; i < s.size(); i++)
            {
                char x = s.at(i);
                unordered_map<char, int>::iterator myfind = myHash.find(x);
                if (myfind == myHash.end())
                {
                    myHash[x] = i;
                    curLen += 1;
                }
                else
                {
                    int foundPosition = myfind->second;
                    for (int j = start; j < foundPosition; j++)
                    {
                        //在这个hashtable里，里面的<char, i>和string s里的字母/位置是一样的
                        myHash.erase(myHash.find(s.at(j)));
                    }
                    //出错点
                    curLen = i - foundPosition; /*foundPosition - (start + 1 );*/
                    start = foundPosition + 1;
                    myHash[x] = i;
                    /*curLen += 1;*/
                }
                maxLen = max(curLen, maxLen);
            }
            return maxLen;
        }
};
