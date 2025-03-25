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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = NULL;
        ListNode* curr = slow;
        ListNode* frw;

        while(curr != NULL){
            frw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = frw;
        }

        ListNode* first = head;
        ListNode* second = prev;

        while(first != NULL && second != NULL){
            if(first->val != second->val){
                return false;
            }
            first = first->next;
            second = second->next;
        }
        return true;
    }
};