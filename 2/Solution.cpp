class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr=dummy;
        int carry=0;
        while(l1 || l2 || carry) {
            int val = carry;
            if(l1) {
                val += l1 -> val;
                l1 = l1 -> next;
            }
            if(l2){
                val += l2 -> val;
                l2 = l2 -> next;
            }
            curr -> next = new ListNode(val%10);
            curr = curr -> next;
            carry = val/10;
        }
        return dummy -> next;
    }
};
 
