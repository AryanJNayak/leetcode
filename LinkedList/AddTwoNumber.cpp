#define node ListNode
class Solution {
public:
    node* addTwoNumbers(node* l1, node* l2) {
        //store carry if sum grater than 10
        int carry = 0;

        node* Head = new node(0);
        node* c = Head;
    
        while(carry==1 || l1!=NULL || l2!=NULL) {
            int sum = 0;
            if(l1) {
                sum+=l1->val;
                l1 = l1 -> next;
            }
            if(l2) {
                sum+=l2->val;
                l2 = l2 -> next;
            }
            //after getting sum 
            sum+=carry;
            
            //add new node as reminder
            node* curr = new node(sum%10);

            // and store carry value
            carry = sum / 10;
            c -> next = curr;
            c = c->next;
        }
        c -> next = NULL;
        return Head -> next;
    }
};