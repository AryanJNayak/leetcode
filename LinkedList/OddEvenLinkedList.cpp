/*
/   given 'head' of LL return LL of 'Odd' node followed by 'Even' node
/   ->  head =   3  ->  2  ->  6  ->  9  ->  4  ->  13  ->  19  ->  34  ->  X
/                o      e      o      e      o      e       o       e
/   ->  return 3 -> 6 -> 4 -> 19 -> 2 -> 9 -> 13 -> 34
/   
/
/
/   ->  make three pointer
/                o     e|x
/   ->  head  =  3  ->  2  ->  6  ->  9  ->  4  ->  13  ->  19  ->  34  ->  X
/   
/
/   ->  o -> next = e -> next
/       e -> next = o -> next -> next
/                       o      x      e
/   ->  head  =  3  ->  6  ->  2  ->  9  ->  4  ->  13  ->  19  ->  34  ->  X
/
/   
/                                  o      x             e
/   ->  head  =  3  ->  6  ->  ->  4  ->  2  ->  9  ->  13  ->  19  ->  34  ->  X
/
/   
/                                             o      x                      e
/   ->  head  =  3  ->  6  ->  ->  4  ->  ->  19  ->  2  ->  9  ->  13  ->  34  ->  X
/
/   
/   
/   if e reaches null o -> next = x  return head;
/   use of x is for store starting of even nodes
*/
#define node ListNode
class Solution {
public:
    node* oddEvenList(node* head) {
        if( !(head) || !(head->next) || !(head->next->next) ) { return head; }
        node* odd = head; // odd nodes
        node* even = head->next; // even node
        node* start_of_even = even; //starting of even nodes

        while(odd->next && even->next) {
            odd -> next = even -> next;//always odd.next is even.next
            even -> next = odd -> next -> next;//even.next is odd.next.next

            //go to next node
            odd = odd -> next;
            even = even -> next;
        }
        //joint odd nodes end with even nodes start
        odd -> next = start_of_even;

    //return head is modified LinkedList head
    return head;
    }
};