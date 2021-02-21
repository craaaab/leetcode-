/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *cursor = head;
        int carry = 0;
        while(l1 || l2 || carry != 0){
            int l1Val = l1 != nullptr ? l1->val : 0;
            int l2Val = l2 != nullptr ? l2->val : 0;
            int sum = l1Val + l2Val + carry;
            carry = sum / 10;

            ListNode *newNode = new ListNode(sum % 10);
            cursor->next = newNode;
            cursor = newNode;

            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
        }
        return head->next;
    }
};
