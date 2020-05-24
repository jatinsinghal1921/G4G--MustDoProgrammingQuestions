// This function should delete node from linked list. The function
// may assume that node exists in linked list and is not last node
// node: reference to the node which is to be deleted
void deleteNode(Node *node)
{
    // Checkinng if actually the node is present.
    // If not then there is nothing to change in the existing list.
    if(node == 0)
        return;
   
    // If the given node is the last element of the list then this function cannot be used 
    // Since this cannot be reflected in original list
    if(node->next == 0)
    {
        cout << "This node cannot be deleted by this method as it is last element of this list";
        return; 
    }
   
    Node* temp = node->next;
    
    node->data = temp->data;
    node->next = temp->next;
    delete temp;
}