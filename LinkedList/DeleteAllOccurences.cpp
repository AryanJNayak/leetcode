#define node struct Node
class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        
        node* curr = *(head_ref);
        while(curr) {
            //in case of 'node->val' equals to 'x' remove 'curr' node
            if(curr->data == x) {
                
                //'curr' is single node
                if(curr->prev == NULL && curr->next == NULL) {
                    *head_ref = NULL;
                    return;
                }
                
                //'curr' is first node
                else if(curr->prev == NULL && curr->next != NULL) {
                    *(head_ref) = curr->next;
                    curr -> next -> prev = NULL;
                }
                
                //'curr' is last node
                else if(curr->prev != NULL && curr->next == NULL) {
                    curr -> prev -> next = NULL;
                }
                
                //'curr' is middle node
                else {
                    curr->prev->next = curr->next;
                    curr->next ->prev = curr->prev;
                }
            }
            
        //next iteration
        curr = curr -> next;
        }
    }
};