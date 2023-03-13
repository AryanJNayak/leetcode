/*
    /   4  -> 5  ->  3  ->  11  ->  9  -> 0
    /         |                           |
    /         |___________________________|
    /
    /   fs
    /   4  -> 5  ->  3  ->  11  ->  9  -> 0
    /         |                           |
    /         |___________________________|
    /
    /         s      f
    /   4  -> 5  ->  3  ->  11  ->  9  -> 0
    /         |                           |
    /         |___________________________|
    /
    /                s              f
    /   4  -> 5  ->  3  ->  11  ->  9  -> 0
    /         |                           |
    /         |___________________________|
    /
    /
    /         f             s              
    /   4  -> 5  ->  3  ->  11  ->  9  -> 0
    /         |                           |
    /         |___________________________|
    /
    /
    /                       f       s              
    /   4  -> 5  ->  3  ->  11  ->  9  -> 0
    /         |                           |
    /         |___________________________|
    /
    / 
    /                                     fs              
    /   4  -> 5  ->  3  ->  11  ->  9  -> 0
    /         |                           |
    /         |___________________________|
    /
    / 
    / in case fast reaches null return NULL
    / if(fast=slow)break
    /
    /   x                                 s              
    /   4  -> 5  ->  3  ->  11  ->  9  -> 0
    /         |                           |
    /         |___________________________|
    /
    /         sx                                         
    /   4  -> 5  ->  3  ->  11  ->  9  -> 0
    /         |                           |
    /         |___________________________|
    /
    /  if (x==s) return s;
    */
#define ln ListNode
class Solution {
public:
    ln *detectCycle(ln *head) {
        if(!head) { return nullptr; }
        
        ln* fast = head;
        ln* slow = head;
        
        while(fast && fast->next) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast) { break; }
        }
        if(!(fast && fast->next )) return nullptr;
        while(slow != head) {
            slow = slow -> next;
            head = head -> next;
        }
        return head;
    }
};