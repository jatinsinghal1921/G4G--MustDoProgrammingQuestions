/*The function removes the loop from the linked list if present
You are required to complete this method*/
void removeTheLoop(Node *head)
{
    Node *slow=head,*fast=head;
    while(fast!=0 && fast->next!=0)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            break;
    }
    if(fast==0 || fast->next==0)
        return;
    
    Node* prev=slow;
    int count=0;
    while(slow != head)
    {
        prev = slow;
        slow = slow->next;
        head = head->next;
        count = 1;
    }  
    
    if(count)
    {
        prev->next = 0;
        return;
    }
    
    slow = slow->next;
    while(slow != head)
    {
        prev = slow;
        slow = slow->next;
    }
    prev->next= 0;
}