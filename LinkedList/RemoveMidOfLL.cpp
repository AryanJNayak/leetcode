#define node ListNode
class Solution {
public:
    node* deleteMiddle(node* head) {
        //only one node in LL
        if(!head || !head->next) {return NULL;}

        //find prev of mid
        node *slow = head, *fast = head, *prev_remove = NULL;
        while(fast && fast -> next) {
            prev_remove = slow; //prev of mid
            slow = slow -> next; //mid
            fast = fast -> next -> next;
        }

        //prev of mid point to mid.next
        prev_remove -> next = slow -> next;

        //delete mid node
        delete slow;

        ///return modified head
        return head;
    }
};