// This function is to segregate the elememtns in the linked list
// This will do the required arrangement by changing the links
Node* segregate(Node *head) {
    
    int zeroCount=0, oneCount=0, twoCount=0;
    Node* temp = head;
    int nodeVal;
    while(temp!=0)
    {
        nodeVal = temp->data;
        switch(nodeVal)
        {
            case 1:
            oneCount++;
            break;
            case 2:
            twoCount++;
            break;
            default:
            zeroCount++;
        }
        temp = temp->next;
    }
    
    temp = head;
    while(zeroCount!=0)
    {
        temp->data = 0;
        temp = temp->next;
        zeroCount--;
    }
    
    while(oneCount!=0)
    {
        temp->data = 1;
        temp = temp->next;
        oneCount--;
    }    
    
    while(twoCount!=0)
    {
        temp->data = 2;
        temp = temp->next;
        twoCount--;
    }    
    return head;
}
