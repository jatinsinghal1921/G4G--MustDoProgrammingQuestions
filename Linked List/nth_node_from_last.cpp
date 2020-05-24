int getNthFromLast(Node *head, int n)
{
    Node* temp = head;
    while(n!=0 && temp !=0)
    {
        temp =temp->next;
        n--;
    }
    if(n==0)
    {
        if(temp == 0)
        {
            return head->data;
        }
        else
        {
            while(temp!=0)
            {
                temp = temp->next;
                head = head->next;
            }
            return head->data;
        }
    }
    return -1;
}