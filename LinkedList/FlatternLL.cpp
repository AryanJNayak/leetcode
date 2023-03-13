
/*
Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 

Note: The flattened list will be printed using the bottom pointer instead of the next pointer.
For more clarity have a look at the printList() function in the driver code.

 

Example 1:
Input:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45

Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.


-> merge(5, merge(10, merge(19, 28)));
-> after merge the next pointer is always NULL

*/
#define node Node
//merge sort logic
node* Merge(node* l1, node* l2) {
    if(l1 == NULL || l2 == NULL) {
        return (l1!=NULL) ? l1 : l2;
    }
    
    node* dummy = new node(-1);
    node* c = dummy;
    while(l1 && l2) {
        if(l1->data <= l2 -> data) {
            c -> bottom = l1;
            l1 = l1 -> bottom;
        } 
        else if(l1->data > l2 -> data) {
            c -> bottom = l2;
            l2 = l2 -> bottom;
        }
        c = c -> bottom;
    }
    c -> bottom = (l1!=NULL) ? l1 : l2 ;
    //always returnable new(LL) next is NULL
    dummy -> next = NULL;
    return dummy -> bottom;
    
}

Node *flatten(Node *root) {
    
    if(root->next==NULL){ return root; }
    
    //get previous of every root
    node* prev = flatten(root->next);

    //merge last(root) and secondLast(prev) LinkedList
    node* merge = Merge (root,prev);
    
    return merge;
}