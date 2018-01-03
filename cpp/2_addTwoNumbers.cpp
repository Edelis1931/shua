/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

            ListNode *dummy = new ListNode(-1);
            ListNode *cur = dummy;
            int carry = 0;

            while (l1 || l2)
            {
                int val1 = (l1) ? l1->val : 0;
                int val2 = (l2) ? l2->val : 0;
                int sum = val1 + val2 + carry;

                carry = (sum > 9) ? 1 : 0;
                sum = sum % 10;

                ListNode *toAdd = new ListNode(sum);
                cur->next = toAdd;
                cur = cur->next;

                l1 = (l1) ? ((l1->next) ? l1->next : 0) : 0;
                l2 = (l2) ? ((l2->next) ? l2->next : 0) : 0;
            }

            if (carry)
            {
                ListNode *toAdd = new ListNode(1);
                cur->next = toAdd;
            }

            return dummy->next;
        }
};
