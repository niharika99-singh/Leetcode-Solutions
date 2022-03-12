/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *curr=head;
        Node* next=NULL;
        
        while(curr){
            next=curr->next;
            Node* copy= new Node(curr->val);
            copy->next=next;
            curr->next=copy;
            
            curr=next;
        }
        
        curr=head;
        while(curr){
            if(curr->random){
                curr->next->random=curr->random->next;
            }
            curr=curr->next->next;
        }
        
        curr=head;
        
        Node* dummyHead = new Node(0);
        Node* cloneListTail=dummyHead;
        Node* copy=NULL;
        
        while(curr){
            next=curr->next->next;
            copy=curr->next;
            
            cloneListTail->next=copy;
            cloneListTail=copy;
            
            curr->next=next;
            
            curr=next;
        }
        
        return dummyHead->next;
    }
};