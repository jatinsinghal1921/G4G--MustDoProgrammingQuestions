
// Reverse list Recursively
Node* reverseListRecursive(Node* head, Node** root)
{
    if(head->next == 0)
    {
        *root = head;
        return head;
    }
    Node* next = reverseListRecursive(head->next, root);
    next->next = head;
    head->next = 0;
    return head;
}


// Utility Function to Reverse list recursively.
Node* reverseList(Node *head)
{
    if(head == 0 || head->next == 0)
        return head;
    
    reverseListRecursive(head, &head);
    return head;
}


// Reverse LL iteratively using 3 pointers
Node* reverseListIterativelyThreePointers(Node *head)
{
    if(head == 0 || head->next == 0)
        return head;
    
    Node *prev = 0, *curr = head, *next = head;
    while(curr!=0)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}


// Reverse LL iteratively using 2 pointers
Node* reverseListIterativelyTwoPointers(Node *head)
{
    if(head == 0 || head->next == 0)
        return head;
    
    Node *prev = head, *curr;
    while(head->next !=0)
    {
        curr = head->next;
        head->next = curr->next;
        curr->next = prev;
        prev = curr;
    }
    return prev;
}