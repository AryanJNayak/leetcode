#define node ListNode
class Solution {
public:
    //merge sort
    node* mergeList(node* left, node* right) {
        //if any of LL is NULL then return another LL 
        //no need to merge null linked list
        if( (left == NULL) || (right == NULL) ) { 
            return (left==NULL) ? right : left ; 
        }

        //new head of sorted linkedlist
        node* ans = new node(0);
        
        //c points sorted linked list fro traverse
        node* c = ans;
        
        //merge sort logic
        while(left && right) {
            if(left->val < right->val) { 
                c -> next = left;
                left = left -> next;
            }
            else {
                c -> next = right;
                right = right -> next;
            }
            c = c -> next; 
        }

        //if any of node are remaining then join to the sorted list
        c -> next = (left==NULL) ? right : left;

        //return ans.next b'coz ans point to '0'
        return ans->next;
    }
    node* sortList(node* head) {
        //in case of head :- null or single list
        if( !(head) || !(head->next) ) { return head; }

        //mid of list is slow
        node* slow = head;
        node* fast = head;
        while(fast && fast->next && fast->next->next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        //to devide list :-  4 2 1 3
        //mid = 2              ^
        node* newHead = slow -> next;//newHead = 1 -> 3 -> NULL
        slow -> next = NULL;//head = 4 -> 2 -> NULL

        node* left = sortList(head);//sort LL for left side
        node* right = sortList(newHead);//sort LL for right side

        return mergeList(left,right);
    }
};