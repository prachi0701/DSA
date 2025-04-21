/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;

        while(temp != NULL){
            Node* copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = temp->next->next;
        }

        temp = head;
        while(temp != NULL){
            if(temp->random == NULL){
                temp->next->random = NULL;
            }else{
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }

        Node* dummy = new Node(-1);
        Node* copyTemp = dummy;
        temp = head;

        while(temp != NULL){
            copyTemp->next = temp->next;
            temp->next = temp->next->next;
            copyTemp = copyTemp->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};