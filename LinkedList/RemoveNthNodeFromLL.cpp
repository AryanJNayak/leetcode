/*
/   removing nth node from end = removing (length-n+1) from starting. to remove 'n' th node we need to previous of 'n'th node
/   
/
/   n = 2
/   head = 1  ->  2  ->  5  ->  16  ->  7
/
/
/   p = head traverse n step from head
/   p
/   1  ->  2  ->  5  ->  16  ->  7
/
/
/   
/   after traverse n step c points to h
/   c      p
/   1  ->  2  ->  5  ->  16  ->  7
/
/
/   while(p.next.next!=null) traverse threw th LL
/
/
/                 c      p
/   1  ->  2  ->  5  ->  16  ->  7
/
/   c->next = c->next->next
*/
#define node ListNode
class Solution {
public:
    node* removeNthFromEnd(node* head, int n) {
        
        if(head -> next == NULL) {  return head -> next; }
        
        //Getting previous of Nth Node
        node* prev_Nth = head;
        while(n != 1) {
            prev_Nth = prev_Nth -> next;
            n--;
        }
        
        //If Its next is NULL means remove first node
        if(prev_Nth -> next == NULL) {return head->next; }
        
        //keep pointer curr. Going to 'n'th node 
        node* curr = head;
        while(prev_Nth && prev_Nth -> next && prev_Nth -> next -> next) {
            curr = curr -> next;
            prev_Nth = prev_Nth -> next;
        }

        //remove nth node
        curr -> next = curr -> next -> next;
        
        return head;
    }
};