/*  This function should rotate list counter-clockwise
    by k and return new head (if changed) */
Node* rotate(Node* head, int k) {
    if(k == 0)
        return head;
    
    Node* temp = head;
    Node *prev = head;
    while(k!=0 and temp!=0)
    {
        k--;
        prev = temp;
        temp = temp->next;
    }
    
    if(temp == 0)
        return head;
    
    prev->next = 0;
    prev = temp;
    while(temp->next != 0)
    {
        temp = temp->next;
    }
    temp->next = head;
    
    return prev;
    
}