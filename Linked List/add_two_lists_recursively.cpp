int listLength(Node* head)
{
    int count = 0;
    while(head)
    {
        count++;
        head = head->next;
    }
    return count;
}


// Create a Node with Data passed as argumentto function  
Node* getNode(int data)
{
    Node* temp = new Node(data);
    temp->next = 0;
    return temp;
}


int addListRecursively(Node* first, Node* second, int carry, Node** head)
{
    int data;
    if(first->next == 0)
    {
        data = first->data + second->data;
        *head = getNode(data%10);
        return data/10;
    }
    carry = addListRecursively(first->next, second->next, carry, head);
    
    data = first->data + second->data + carry;
    Node* temp = getNode(data%10);
    temp->next = *head;
    *head = temp;
    
    return (data/10);
}


int traverseListByDiff(Node* first, Node* second, int diff, int carry, Node** head)
{
    int data;
    if(diff == 0)
        return addListRecursively(first, second, carry, head);

    diff--;
    carry = traverseListByDiff(first->next, second, diff, carry, head);        
    
    data = first->data + carry;
    Node* temp = getNode(data%10);
    temp->next = *head;
    *head = temp;

    return(data/10);
}


// write a function returns the resultant linked list
Node* addTwoLists(Node* first, Node* second) {
    if(first == 0)
        return second;
    if(second == 0)
        return first;
        
    int l1 = listLength(first);
    int l2 = listLength(second);
    
    int diff = l1-l2;
    int carry = 0;
    Node* head;
    if(diff>0)
    {
        carry = traverseListByDiff(first, second, diff, carry, &head);
    }
    else if(diff<0)
    {
        diff = -diff;
        carry = traverseListByDiff(second, first, diff, carry, &head);
    }
    else
    {
        carry = addListRecursively(first, second, carry, &head);
    }
    if(carry == 1)
    {
        Node* temp = getNode(1);
        temp->next = head;
        head = temp;
    }
    return head;
}

