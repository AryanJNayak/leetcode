class Solution {
public:
    /*
    /  prev = NULL
    /  NULL   4  ->  5  ->  11  ->  15  ->  9  ->  13 -> X
    /   ^     ^      ^
    /  prev  head    nxt
    /
    /
    /  nxt = head ->next
    /  head -> next prev
    /  head = nxt
    /  NULL <- 4     5  ->  11  ->  15  ->  9  ->  13 -> X
    /   ^      ^      ^
    /  prev   head    nxt
    /
    /
    /  nxt = head ->next
    /  head -> next prev
    /  head = nxt
    /  NULL <- 4  <- 5     11  ->  15  ->  9  ->  13 -> X
    /          ^      ^     ^
    /         prev   head  nxt
    /
    /
    /  nxt = head ->next
    /  head -> next prev
    /  head = nxt
    /  NULL <- 4  <- 5  <-  11    15  ->  9  ->  13 -> X
    /                 ^      ^     ^
    /               prev   head   nxt
    /
    /
    /  nxt = head ->next
    /  head -> next prev
    /  head = nxt
    /  NULL <- 4  <- 5  <-  11 <- 15     9  ->  13 -> X
    /                       ^      ^     ^
    /                      prev   head  nxt
    /
    /
    /  nxt = head ->next
    /  head -> next prev
    /  head = nxt
    /  NULL <- 4  <- 5  <-  11 <- 15  <- 9     13  -> X
    /                                    ^      ^     ^
    /                                   prev   head   nxt
    /
    /
    /  nxt = head ->next
    /  head -> next prev
    /  head = nxt
    /  NULL <- 4  <- 5  <-  11 <- 15  <- 9  <- 13    X
    /                                          ^     ^  
    /                                         prev  head
    /
    /  return prev
    /  prev = 13  ->  9  ->  15  ->  11  ->  5  ->  4  ->  X  
    */
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        while(head) {
            ListNode* nxt = head-> next;
            head -> next =  prev ;
            prev = head;
            head = nxt;
        }
        return prev;
    }
};