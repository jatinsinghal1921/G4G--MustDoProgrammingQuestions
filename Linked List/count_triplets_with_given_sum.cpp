nt countTriplets(struct Node* head, int k) 
{ 
    if(head == 0 || head->next == 0 || head->next->next == 0)
    {
        return 0;
    }
    
    Node* trav = head;
    Node *head2, *temp;
    while(trav!=0)
    {
        temp = new Node(trav->data);
        
        if(head2 == 0)
        {
            head2 = temp;
        }
        else
        {
            temp->next = head2;
            head2 = temp;
        }
        trav = trav->next;
    }
    
    int count = 0;
    Node *temp1, *temp2;
    long remainingSum, partialSum;
    while(head->next->next != 0)
    {
        remainingSum = k-head->data;
        temp1 = head->next;
        temp2 = head2;
        while(temp1->data < temp2->data)
        {
            partialSum = temp1->data + temp2->data;
            if(partialSum == remainingSum)
            {
                count++;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            else if(partialSum < remainingSum)
            {
                temp1 = temp1->next;
            }
            else
            {
                temp2= temp2->next;
            }
        }
        head = head->next;
    }
    return count; 
    
} 