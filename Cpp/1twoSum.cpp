#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {

            int size = nums.size();
            unordered_map<int, int> myHashTable;
            unordered_map<int, int>::iterator it;
            int firstValue;
            int secondValue;

            for (int i = 0; i < size; i++)
            {
                it = myHashTable.find(nums.at(i));
                if (it == myHashTable.end())
                {
                    int keyToPut = target - nums.at(i);
                    myHashTable[keyToPut] = i;
                }
                else
                {
                    firstValue = min(i, myHashTable.find(nums.at(i))->second);
                    secondValue = max(i, myHashTable.find(nums.at(i))->second);
                    break;
                }
            }

            vector<int> result;

            result.push_back(firstValue);
            result.push_back(secondValue);

            return result;
        }
};

