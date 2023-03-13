class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        /*
        /   4  ->  5  ->  69  ->  3  ->  22  ->  1  ->  10
        /  | |
        /  s f
        /
        /  4  ->  5  ->  69  ->  3  ->  22  ->  1  ->  10
        /         |      |
        /         s      f
        /
        /  4  ->  5  ->  69  ->  3  ->  22  ->  1  ->  10
        /                |              |
        /                s              f
        /
        /  4  ->  5  ->  69  ->  3  ->  22  ->  1  ->  10
        /                        |                      |
        /                        s                      f
        / 
        / s is answer
        */

        //slow traverse one time & fast traverse two time
        ListNode* slow = head, *fast = head;
        while(fast && fast->next) {
            slow = slow -> next;
            fast  = fast->next->next;
        }
        
        return slow;
    }
};