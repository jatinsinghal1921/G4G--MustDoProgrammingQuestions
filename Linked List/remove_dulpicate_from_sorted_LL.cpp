// root: head node
Node *removeDuplicates(Node *root)
{
    if(root == 0 || root->next == 0)
    {
        return root; 
    }
    Node* temp = root;
    Node* nodeToBeDeleted;
    while(temp->next != 0)
    {
        if(temp->data == temp->next->data)
        {
            nodeToBeDeleted = temp->next;
            temp->next = nodeToBeDeleted->next;
            delete nodeToBeDeleted;
        }
        else
        {
            temp = temp->next;    
        }
    }
    return root;
}