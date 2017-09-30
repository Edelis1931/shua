/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(-1);
        ListNode curr = dummy;
        int carry = 0;
        int sum = 0;
        
        while (l1 != null || l2 != null)
        {
            int val1 = (l1 == null) ? 0 : l1.val;
            int val2 = (l2 == null) ? 0 : l2.val;
            sum = val1 + val2 + carry;
            carry = (sum > 9) ? 1 : 0;
            sum = sum % 10;
            ListNode toAdd = new ListNode(sum);
            curr.next = toAdd;
            curr = curr.next;
            
            l1 = (l1 != null) ? ((l1.next == null) ? null : l1.next) : null;
            l2 = (l2 != null) ? ((l2.next == null) ? null : l2.next) : null;
        }
        
        if (carry == 1)
        {
            ListNode toAdd = new ListNode(1);
            curr.next = toAdd;
        }
        
        return dummy.next;
    }
}