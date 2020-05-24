int getListLength(Node* head)
{
    int count=0;
    while(head!=0)
    {
        count++;
        head = head->next;
    }
    return count;
}


/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int intersectPoint(Node* head1, Node* head2)
{
    if(head1 == 0 || head2 == 0)
    {
        return -1;
    }
    int l1 = getListLength(head1);
    int l2 = getListLength(head2);
    int diff = l1-l2;
    if(diff>0)
    {
        while(diff)
        {
            head1 = head1->next;
            diff--;
        }
    }
    else if(diff<0)
    {
        diff = -diff;
        while(diff)
        {
            head2 = head2->next;
            diff--;
        }
    }
    while(head1!=0)
    {
        if(head1 == head2)
        {
            return head1->data;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return -1;
}