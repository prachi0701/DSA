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

    int getLength(ListNode* head){
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL){
            len++;
            temp = temp->next;
        }
        return len;
    }

    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return true;
        }

        int len = getLength(head);
        int mid = len/2;
        ListNode* slow = head;

        while(mid-1 != 0){
            slow = slow->next;
            mid--;
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
        // slow->next = curr;

        ListNode* start = head;
        ListNode* end = prev;
        while(end != NULL && start != NULL){
            if(start->val != end->val){
                return false;
            }
            start = start->next;
            end = end->next;
        }
        return true;
    }
};