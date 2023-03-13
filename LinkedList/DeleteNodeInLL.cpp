class Solution {
public:
    void deleteNode(ListNode* currentNode) {
        ListNode* nextNode = currentNode->next;
        currentNode -> val = nextNode -> val;
        currentNode -> next = nextNode -> next;
        nextNode -> next = nullptr;
        delete(nextNode);
    }
};