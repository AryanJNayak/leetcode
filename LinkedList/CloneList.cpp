class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) { return head; }
        Node* curr = head;
        //every node next is copy node of it-self
        while(curr) {
            //i.e.  2 -> 4
            Node* d = new Node(curr -> val);
            d -> next = curr -> next;
            
            // 2 -> 2 -> 4
            curr -> next = d;
            
            //next iteration
            curr = d -> next;
        }
        
        //assign random and next node of every copy node
        curr = head;
        while(curr) {
            if(curr -> random) {
            curr -> next -> random = curr -> random -> next;
            }
            curr = curr -> next -> next;
        }

        //remove copy node from original LinkedList and get back our original LinkedList
        curr = head;
        Node* H = curr -> next;
        while(curr) {
            Node* d = curr -> next;
            curr -> next = d -> next;
            if(d->next) {
                d -> next = d -> next -> next;
            }
            curr = curr -> next;
        }
        return H;
    }
};