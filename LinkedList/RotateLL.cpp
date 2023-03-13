#define node ListNode
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        //single or null node
        if(!head || !head->next || k==0) {return head;}
        
        node* curr = head;
        int len = 1;
        
        //count length
        while(curr->next) {
            curr = curr -> next;
            len++;
        }

        //circulat LL
        curr->next = head;

        //if k is grater then length so modulo make it in range
        k = k % len;

        //rotate by right 'k' places
        k = len - k;
        while(k--) {
            curr = curr -> next;
        }

        //new head
        head = curr->next;
        
        //break cicular linkedlist
        curr->next = NULL;

        //return head
        return head;
    }
};