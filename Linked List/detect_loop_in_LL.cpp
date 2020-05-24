
int detectloop(Node *head) {
    Node *slow=head,*fast=head;
    while(fast!=0 && fast->next!=0)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return 1;
    }
    return 0;
}