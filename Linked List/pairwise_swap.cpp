struct Node* pairwise_swap(struct Node* head)
{
    if(head==0 || head->next==0)
        return head;

    Node* temp = head->next;
    head->next = temp->next;
    temp->next = head;

    head->next = pairwise_swap(head->next);
    return temp;
}