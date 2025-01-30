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
            len++;
            temp = temp->next;
        }
        return len;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = getLength(head);
        if(len == 1){
            return NULL;
        }
        int remove = len - n;
        if(remove == 0){
            return head->next;
        }
        int cnt = 1;
        ListNode* temp = head;

        while(cnt <= remove){
            if(cnt == remove){
                if(temp->next != NULL){
                    temp->next = temp->next->next;
                }else{
                    temp->next = NULL;
                }
            }else{
                temp = temp->next;
            }
            cnt++;
        }
        return head;
    }
};