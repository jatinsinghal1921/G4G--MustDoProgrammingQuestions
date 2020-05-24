Node* sortedMerge(Node* head1,   Node* head2)
{
    if(head1 == 0)
        return head2;
    if(head2 == 0)
        return head1;
    
    Node* head = 0, *temp = head;
    while(head1 && head2)
    {
        if(head1->data <= head2->data)
        {
          if(head==0)
          {
              head = head1;
              temp = head1;
          }
          else
          {
              temp->next = head1;
              temp = head1;
          }
          head1 = head1->next;
      }
      else
      {
          if(head == 0)
          {
              head = head2;
              temp = head2;
          }
          else
          {
              temp->next = head2;
              temp = head2;
          }
          head2 = head2->next;
      }
    }
    
    if(head1)
    {
      temp->next = head1;
    }
    else
    {
      temp->next = head2;
    }
    
    return head;
}