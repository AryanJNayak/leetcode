#define node ListNode
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        node *curr = head;
        int cnt = 0;

        // after cnt==k curr points to ('K' + 1)-th  node from 'head'
        while (cnt < k)
        {

            // between the iteration 'curr' = NULL indicate left-out node so we not reverse
            if (!curr)
            {
                return head;
            }

            curr = curr->next;
            cnt++;
        }

        // starting from 'head' reverse nodes until 'K'
        node *p = NULL, *c = head;
        cnt = 0; // for counting group size

        while (cnt < k)
        {
            // current node's next is store
            node *nxt = c->next;

            // curr node point previon node
            c->next = p;

            // previous node is current node || head node
            p = c;

            // current node is current's next node
            c = nxt;
            cnt++; // counting
        }

        // entire task perform for next group [line:8] after (k + 1)th node
        // 3 2 1 4 5 6 7
        //       ^
        //      curr

        head->next = reverseKGroup(curr, k);

        return p; // returning head node [line:29]
    }
};