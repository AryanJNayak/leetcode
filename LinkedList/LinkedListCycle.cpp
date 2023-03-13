#define ln ListNode
class Solution
{
public:
    /*
    /   4  -> 5  ->  3  ->  11  ->  9  -> 0
    /         |                           |
    /         |___________________________|
    /
    /   s     f
    /   4  -> 5  ->  3  ->  11  ->  9  -> 0
    /         |                           |
    /         |___________________________|
    /
    /         s             f
    /   4  -> 5  ->  3  ->  11  ->  9  -> 0
    /         |                           |
    /         |___________________________|
    /
    /                s                    f
    /   4  -> 5  ->  3  ->  11  ->  9  -> 0
    /         |                           |
    /         |___________________________|
    /
    /
    /                f       s
    /   4  -> 5  ->  3  ->  11  ->  9  -> 0
    /         |                           |
    /         |___________________________|
    /
    /
    /                              fs
    /   4  -> 5  ->  3  ->  11  ->  9  -> 0
    /         |                           |
    /         |___________________________|
    /
    / in case fast reaches NULL it means no loop in lisnked list
    / f == s means loop in linked list
    */

    bool hasCycle(ln *head)
    {
        if (head == NULL)
        {
            return 0;
        }

        ln *slow = head;
        ln *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow)
            {
                return 1;
            }
        }

        return 0;
    }
};