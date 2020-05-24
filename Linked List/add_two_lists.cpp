// Create a Node with Data passed as argumentto function  
Node* getNode(int data)
{
    Node* temp = new Node(data);
    temp->next = 0;
    return temp;
}


// Add list to the carry and return carry
int addListToCarry(Node* head, int carry, Node** trav)
{
    int data;
    Node* temp;
    
    while(head)
    {
        data = head->data + carry;
        carry = data/10;
        data = data%10;
        temp = getNode(data);
        (*trav)->next = temp;
        (*trav) = temp;
        head = head->next;
    }
    return carry;
}


// write a function returns the resultant linked list
Node* addTwoLists(Node* first, Node* second) {
    if(first == 0)
        return second;
    if(second == 0)
        return first;
    
    
    // Add data of 2 lists
    Node *head=0,*temp,*trav;
    int data,carry=0;
    while(first && second)
    {
        data = first->data + second->data + carry;
        carry = data/10;
        data = data%10;
        
        temp = getNode(data);
        if(head == 0)
            head = temp;
        else
            trav->next = temp;

        trav = temp;
        first = first->next;
        second = second->next;
    }
    if(first)
        carry = addListToCarry(first, carry, &trav);
    else if(second)
        carry = addListToCarry(second, carry, &trav);
    
    if(carry)
    {
        temp = getNode(1);
        trav->next = temp;
    }

    return head;
}