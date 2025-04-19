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
        ListNode* temp = head;
        int len = 0;
        while(temp != NULL){
            temp = temp->next;
            len++;
        }
        return len;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        int len = getLength(head);
        k = k%len;

        ListNode* start = head;
        ListNode* last;
        ListNode* secLast;
        ListNode* temp = head;

        while(temp->next->next != NULL){
            temp = temp->next;
        }
        secLast = temp;
        last = temp->next;

        while(k != 0){
            last->next = start;
            secLast->next = NULL;
            temp = last;
            while(temp->next->next != NULL){
                temp = temp->next;
            }
            start = last;
            last = secLast;
            secLast = temp;
            k--;
        }

        return start;
    }
};