/*
/ ->    1  ->  3  ->  3  ->  3  ->  1  ->  X
/       find middle using slow and fast pointer
/
/
/                  s(mid)
/ ->    1  ->  3  ->  3  ->  3  ->  1  ->  X
/
/
/ ->    s -> next = rev(s->next);
/                     s    (s->next)
/       1  ->  3  ->  3  ->  1  ->  3  ->  X
/
/
/ ->    s = s-> next
/       x = head
/       x                    s
/       1  ->  3  ->  3  ->  1  ->  3  ->  X
/
/
/ ->    if s -> val != x -> val return false
/       else s=  s -> next and x = x -> next
/
/
/              x                    s
/       1  ->  3  ->  3  ->  1  ->  3  ->  X
/
/
/ ->    's' reaches NULL so no need to check for this case
/                     x                    s
/       1  ->  3  ->  3  ->  1  ->  3  ->  X
/
*/
#define node ListNode
class Solution {
public:
    node* rev(node* head) {
        node* prev = NULL;
        node* nxt = NULL;
        while(head) {
            nxt = head -> next;
            head -> next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }
    bool isPalindrome(node* head) {
        node* sl = head;
        node* fs = head;
        while(fs->next && fs->next->next) {
            sl = sl -> next;
            fs = fs -> next -> next;
        }
        sl -> next = rev(sl->next);
        sl = sl -> next;
        while(sl) {
            if(sl->val != head->val) {return false;}
            head = head -> next;
            sl = sl -> next;
        }
        return true;
    }
};