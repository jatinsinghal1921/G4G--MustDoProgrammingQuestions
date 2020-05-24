int addDigitToList(Node* head, int n)
{
    if(head == 0)
    {
        return n;
    }
    n = addDigitToList(head->next, n);
    if(n == 0)
        return n;
    
    int data = head->data + n;
    head->data = data%10;
    return  (data/10);
}


Node *addValue(Node *head, int n) {
    if(n == 0)
        return head;
    
    int carry = addDigitToList(head, n);
    if(carry == 1)
    {
        Node* temp = new Node(1);
        temp->next = head;
        return temp;
    }
    return head;