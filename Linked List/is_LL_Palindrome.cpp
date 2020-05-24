bool isLinkedListPalindrome(Node** root, Node* head)
{
    if(head == 0)
        return true;
    bool status = isLinkedListPalindrome(root, head->next);
    if(status && ((*root)->data == head->data))
    {
        *root = (*root)->next;
        return true;
    }
    return false;
}


/*You are required to complete this method */
bool isPalindrome(Node *head)
{
    if(head==0 || head->next ==0)
    {
        return true;
    }
    return isLinkedListPalindrome(&head, head);
}